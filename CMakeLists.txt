cmake_minimum_required(VERSION 3.18)

# set the project name
project(testcmplx VERSION 1.0.30)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# add the executable
add_executable(testcmplx testcmplx.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt)
# target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

configure_file(testcmplx.h.in testcmplx.h)

target_include_directories(testcmplx PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )


# testing stuff #                       
enable_testing()

# add test #
add_test(NAME testcmplx COMMAND testcmplx  2 )
