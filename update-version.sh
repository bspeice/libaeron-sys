#!/bin/bash

# Script to bump the version
# ./update-version.sh 1.47.0

set -eu

version="${1:?Usage: $0 <version>}"

script="$( readlink -f $0 )"
basedir="${script%/*}"
cd "${basedir}"

update_codecs() {
    crate=$1
    echo "Generating codecs..."
    codec_dir="${crate}/generated/c"
    git rm -rfq --ignore-unmatch "${codec_dir}"
    (
        cd "${crate}/aeron" && \
            ./gradlew -Dcodec.target.dir="${codec_dir}" \
                :aeron-archive:generateCCodecs --no-daemon
    )
    git add "${codec_dir}"
}

echo "Updating submodules..."
git submodule update --init --remote
git submodule foreach git checkout "${version}"

for crate in "${basedir}"/libaeron*-sys; do
    echo "Updating version for ${crate##*/}..."
    sed -i \
        -e "s#^version = \"[0-9.]*\"\$#version = \"${version}\"#" \
        -e "s#\(^libaeron.*version = \)\"=[0-9.]*\"#\\1\"=${version}\"#" \
        "${crate}/Cargo.toml"

    git add "${crate}/aeron" "${crate}/Cargo.toml"

    if [[ "libaeron_archive_c_client-sys" == "${crate##*/}" ]]; then
        update_codecs "${crate}"
    fi
done

echo "Testing..."
cargo clean -v
cargo test --quiet

git status

echo "If everything looks OK, run: git commit -m 'Upgrade to Aeron ${version}'"
