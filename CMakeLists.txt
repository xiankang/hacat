#CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

#测试目录
message("CMAKE_SOURCE_DIR= ${CMAKE_SOURCE_DIR}")
message("CMAKE_BINARY_DIR= ${CMAKE_BINARY_DIR}")
message("PROJECT_SOURCE_DIR= ${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR= ${PROJECT_BINARY_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR= ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR= ${CMAKE_CURRENT_BINARY_DIR}")

#打开编译步骤实际调用的命令、参数一一列出
set(CMAKE_VERBOSE_MAKEFILE on)

#设置cmake module路径
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# apple下设置
# 设置c language dialect 为gnu11
# 设置c++ language dialect 为GNU++14[-std=gnu++14]
# 设置c++ standard library 为libc++

message(STATUS "operation system is ${CMAKE_SYSTEM}")

option(USE_LIBC++ "Use libc++ instead of libstdc++" ${APPLE})
if(USE_LIBC++)
    message("USE_LIBC++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    add_definitions("-std=gnu++11")
endif()

# find_package(CXX11 REQUIRED)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_FLAGS}")

# if(${CMAKE_C_COMPILER_ID} MATCHES "Clang" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
# 	set(CMAKE_COMPILER_IS_CLANG TRUE)
# endif()

# include(GNUInstallDirs)

# if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
# 	set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-function -Werror-implicit-function-declaration -Wno-missing-field-initializers ${CMAKE_CXX_FLAGS} -fno-strict-aliasing")
# 	set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-unused-function -Werror-implicit-function-declaration -Wno-missing-braces -Wno-missing-field-initializers ${CMAKE_C_FLAGS} -std=gnu99 -fno-strict-aliasing")

# 	option(USE_LIBC++ "Use libc++ instead of libstdc++" ${APPLE})
# 	if(USE_LIBC++)
# 		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
# 	endif()
# elseif(MSVC)
# 	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
# 		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
# 	else()
# 		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
# 	endif()

# 	# Disable pointless constant condition warnings
# 	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4127 /wd4201 /wd4456 /wd4457 /wd4458 /wd4459 /wd4595")
# endif()

# if(WIN32)
# 	add_definitions(-DUNICODE -D_UNICODE -D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_WARNINGS)
# endif()

# if(MSVC)
# 	set(CMAKE_C_FLAGS_DEBUG "/DDEBUG=1 /D_DEBUG=1 ${CMAKE_C_FLAGS_DEBUG}")
# 	set(CMAKE_CXX_FLAGS_DEBUG "/DDEBUG=1 /D_DEBUG=1 ${CMAKE_C_FLAGS_DEBUG}")

# 	if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
# 		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
# 		set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
# 		set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /SAFESEH:NO")
# 	endif()
# else()
# 	if(MINGW)
# 		set(CMAKE_WIDL "widl" CACHE STRING "wine IDL header file generation program")
# 		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_WIN32_WINNT=0x0600 -DWINVER=0x0600")
# 		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0600 -DWINVER=0x0600")
# 	endif()
# 	set(CMAKE_C_FLAGS_DEBUG "-DDEBUG=1 -D_DEBUG=1 ${CMAKE_C_FLAGS_DEBUG}")
# 	set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG=1 -D_DEBUG=1 ${CMAKE_C_FLAGS_DEBUG}")
# endif()

# if(APPLE)
# 	set(CMAKE_MACOSX_RPATH TRUE)
# 	set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
# 	list(APPEND CMAKE_INSTALL_RPATH "@loader_path/" "@executable_path/")
# elseif(UNIX)
# 	option(USE_XDG "Utilize XDG Base Directory Specification" ON)
# 	if(USE_XDG)
# 		add_definitions(-DUSE_XDG)
# 	endif()

# 	if(NOT UNIX_STRUCTURE)
# 		list(APPEND CMAKE_INSTALL_RPATH "$ORIGIN")
# 	endif()
# endif()

#项目信息
project(hacat)

#添加子目录
add_subdirectory(algorithm)
add_subdirectory(test)
add_subdirectory(app)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

#指定生成目标
add_executable(hacat ${app_SRCS})

#添加test模块
include(TestBins)
use_test_module(${PROJECT_NAME})

include(AlgorithmBins)
use_algorithm_module(${PROJECT_NAME})