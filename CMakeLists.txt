cmake_minimum_required(VERSION 3.18)

# set the project name
project(testcmplx VERSION 1.0.30)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
# set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)

# function(add_module name)
#     file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})
#     add_custom_target(${name}.pcm
#             COMMAND
#                 ${CMAKE_CXX_COMPILER}
#                 -std=c++20
#                 -stdlib=libc++
#                 -fmodules
#                 -c
#                 ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
#                 -Xclang -emit-module-interface
#                 -o ${PREBUILT_MODULE_PATH}/${name}.pcm
# 
#             )
# endfunction()
# find_library(FMT_LIB fmt)

# add_compile_options(-stdlib=libc++)
# add_compile_options(-lfmt)
# FetchContent_Declare(fmt
#     URL file:///usr/lib/x86_64-linux-gnu/libfmt.so.7.1.3
# )

# FetchContent_MakeAvailable(fmt)
# target_link_libraries(fmt -lfmt -L/usr/lib/x86_64-linux-gnu)


# add the executable
add_executable(testcmplx testcmplx.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt)
# target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

configure_file(testcmplx.h.in testcmplx.h)

target_include_directories(testcmplx PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
