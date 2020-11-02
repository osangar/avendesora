# This file is part of avendesora.
#
# avendesora is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# avendesora is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# avendesora.  If not, see <https://www.gnu.org/licenses/>.

# Using the first version of CMake released in 2020 appears to be within
# reason.
#
# `FATAL_ERROR` is specified so that CMake versions <=2.4 fail with an error
# instead of just a warning. This option is ignored with versions >=2.6.
cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(avendesora VERSION 1.0.0.0
                   DESCRIPTION "Multi game console emulator"
                   HOMEPAGE_URL "https://github.com/osangar/avendesora"
                   LANGUAGES CXX)

# avendesora only supports the `g++` and `clang++` compilers.
# Using the first versions released in 2020 of both compilers appears to be
# within reason.
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION LESS "8.4")
        message(FATAL_ERROR "You must use a version of g++ >=8.4.")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (CMAKE_CXX_COMPILER_VERSION LESS "10.0.0")
        message(FATAL_ERROR "You must use a version of clang++ >=10.0.0.")
    endif()
endif()

# Everything checks out, continue with the configuration.
add_subdirectory(src)