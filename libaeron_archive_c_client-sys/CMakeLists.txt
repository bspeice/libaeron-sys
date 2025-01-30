cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

# When Archive API is built, cmake calls out to Gradle to generate SBE codecs.
# This greatly complicates the build, especially since Gradle proceeds with
# downloading Java dependencies off the internet, which is not desirable.
# Let's replace gradlew with "echo" to turn it into a no-op:
set(GRADLE_WRAPPER "echo")

# And instead, include pre-generated codecs
include_directories("generated")

# These aren't needed anymore
set(Java_JAR_EXECUTABLE "DISABLED_FOR_LIBAERON_SYS")
set(Java_JAVA_EXECUTABLE "DISABLED_FOR_LIBAERON_SYS")
set(Java_JAVAC_EXECUTABLE "DISABLED_FOR_LIBAERON_SYS")
set(Java_JAVAH_EXECUTABLE "DISABLED_FOR_LIBAERON_SYS")
set(Java_JAVADOC_EXECUTABLE "DISABLED_FOR_LIBAERON_SYS")

# Proceed with the build
add_subdirectory("aeron")
