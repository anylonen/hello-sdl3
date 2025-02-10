cmake_minimum_required(VERSION 3.16)

project(ex02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(ex02 main.cpp  )

target_link_libraries(ex02 PRIVATE SDL3::SDL3-shared)

include(GNUInstallDirs)
install(
  TARGETS ex02
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
