cmake_minimum_required(VERSION 3.10)
option(BUILD_TESTS "Build tests" OFF)
option(PACK "pack" OFF)
project(prototype)

file(GLOB SOURCES "ConceptualExample.cpp" "MediaPlayer01.cpp" "MediaPlayer02.cpp" "PluggableAdapterDesign.cpp" "Program.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

if(PACK)
  install(TARGETS prototype
    RUNTIME DESTINATION bin
  )
  include(CPack.cmake)
endif()

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB TEST_SOURCES  "Test.cpp")
  add_executable(check ${TEST_SOURCES})
  target_link_libraries(check gtest_main)
  add_test(NAME check COMMAND check)
endif()
