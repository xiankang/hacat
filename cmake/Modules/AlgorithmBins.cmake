set(ALGORITHM_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/algorithm
)

macro(use_algorithm_module _target)
    target_link_libraries(${_target} algorithm)
    include_directories(${ALGORITHM_INCLUDE_DIRS})
endmacro()
