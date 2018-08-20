cmake_minimum_required(VERSION 3.10.0)
set(FIND_MODE REQUIRED)

project(algorithm)

add_subdirectory(base)
add_subdirectory(divide_conquer)
add_subdirectory(sort)
add_subdirectory(common)

set(algorithm_SRCS 
    ${divide_conquer_SRCS}
    ${sort_SRCS}
    ${base_SRCS}
    ${common_SRCS}
)


source_group(base 
FILES
${base_SRCS})

source_group(divide_conquer 
FILES
${divide_conquer_SRCS})

source_group(sort 
FILES
${sort_SRCS})

source_group(common
FILES
${common_SRCS})


#添加头文件目录
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

add_library(${PROJECT_NAME} ${algorithm_SRCS})