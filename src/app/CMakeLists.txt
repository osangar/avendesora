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

set(SRCS avendesora.cpp main.cpp)
set(HDRS avendesora.h platform/platform.h)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(X11 REQUIRED)

    set(PLATFORM_SRCS platform/linux/input.cpp
                      platform/linux/platform.cpp
                      platform/linux/window.cpp)

    set(PLATFORM_HDRS platform/linux/input.h
                      platform/linux/platform.h
                      platform/linux/window.h)

    add_executable(avendesora ${SRCS}
                              ${PLATFORM_SRCS}
                              ${HDRS}
                              ${PLATFORM_HDRS})

    target_link_libraries(avendesora PRIVATE ${X11_LIBRARIES})
    target_include_directories(avendesora PRIVATE ${X11_INCLUDE_DIR})
else()
    message(FATAL_ERROR "avendesora requires a Linux OS to compile.")
endif()

set_target_properties(avendesora PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS ON)

target_compile_options(avendesora PRIVATE -Wall -Werror -Wextra)