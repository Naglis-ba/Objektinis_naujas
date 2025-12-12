cmake_minimum_required(VERSION 3.28)
project(Objektinis)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(includeClass)
file(GLOB SOURCES "srcClass/*.cpp")
file(GLOB DATA_FILES "${CMAKE_SOURCE_DIR}/data/*.txt")

add_custom_target(copy_data ALL
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          ${DATA_FILES}
          $<TARGET_FILE_DIR:Objektinis>
)

add_executable(Objektinis ${SOURCES})