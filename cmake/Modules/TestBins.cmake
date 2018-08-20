set(TEST_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/test
)

macro(use_test_module _target)
    target_link_libraries(${_target} autotest)
    include_directories(${TEST_INCLUDE_DIRS})
endmacro()