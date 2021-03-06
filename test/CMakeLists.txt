cmake_minimum_required(VERSION 3.10.0)

project(autotest)
#查找当前目录下的所有源文件
#并将名字保存到DIR_LIB_SRCS变量
# aux_source_directory(. DIR_LIB_SRCS)

#头文件
set(test_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/i_task.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/i_task.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_base.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_base.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_find_maximum_subarray.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_find_maximum_subarray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_matrix.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_matrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_sort.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_sort.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_knapsack.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_knapsack.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_red_black_tree.h
    ${CMAKE_CURRENT_SOURCE_DIR}/test_red_black_tree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/string_ex.h
    ${CMAKE_CURRENT_SOURCE_DIR}/test_manager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_manager.cpp
)

source_group(Source 
FILES
${test_SRCS})

#添加头文件目录
# include_directories(../algorithm/base ../algorithm/divide_conquer ../algorithm/sort)

#添加包含链接库
# link_libraries(algorithm)

#设置库文件存放路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#设置执行文件存放路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#生成静态链接库
add_library(${PROJECT_NAME} ${test_SRCS})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

include(AlgorithmBins)
use_algorithm_module(${PROJECT_NAME})