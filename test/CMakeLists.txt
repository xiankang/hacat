project(test)
#查找当前目录下的所有源文件
#并将名字保存到DIR_LIB_SRCS变量
# aux_source_directory(. DIR_LIB_SRCS)

#头文件
set(test_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/i_task.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/i_task.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_base.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_find_maximum_subarray.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_find_maximum_subarray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_matrix.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_matrix.cpp
)

#添加头文件目录
include_directories(../algorithm/base ../algorithm/divide_conquer ../algorithm/sort)

#添加包含链接库
# link_libraries(algorithm)

#设置库文件存放路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#设置执行文件存放路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#生成静态链接库
add_library(test ${test_SRCS})
target_link_libraries(test algorithm)