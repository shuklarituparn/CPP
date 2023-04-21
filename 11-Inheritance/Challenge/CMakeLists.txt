cmake_minimum_required(VERSION 3.0)

# Set the project name and version
project(Challenge VERSION 1.0)

# Add all source and header files in the current directory to the project
file(GLOB SOURCES *.cpp *.h)

# Create the executable
add_executable(my_executable ${SOURCES})

