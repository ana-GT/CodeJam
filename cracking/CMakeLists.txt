cmake_minimum_required( VERSION 2.8 )

add_executable( chapter13_1 chapter13_1.cpp )
set_target_properties( chapter13_1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

add_executable( chapter13_1a chapter13_1a.cpp )
set_target_properties( chapter13_1a PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )