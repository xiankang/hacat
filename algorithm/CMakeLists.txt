project(algorithm)

add_subdirectory(base)
add_subdirectory(divide_conquer)
add_subdirectory(sort)

set(algorithm_SRCS 
    ${divide_conquer_SRCS}
    ${sort_SRCS}
    ${base_SRCS}
)


source_group(base ${base_SRCS})
source_group(divide_conquer ${divide_conquer_SRCS})
source_group(sort ${sort_SRCS})

#添加头文件目录
include_directories(./base ./divide_conquer ./sort)

add_library(algorithm ${algorithm_SRCS})