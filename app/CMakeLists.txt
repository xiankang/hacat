project(app)

#添加头文件目录
set(test_HEADERS ${CMAKE_SOURCE_DIR}/test)

# message（"test_head= ${test_HEADERS}")

# target_include_directories(hacat PUBLIC 
#     $<BUILD_INTERFACE:${test_HEADERS}>
#     $<INSTALL_INTERFACE:include/hacat>
# )

#头文件目录
include_directories(${test_HEADERS} ../algorithm/base ../algorithm/divide_conquer ../algorithm/sort)

#链接库目录
#link_directories()

#指定生成目标
add_executable(hacat main.cpp)

#链接库
target_link_libraries(hacat test algorithm)

