cmake_minimum_required(VERSION 3.7)

project(TestLib VERSION 1.0.0)

## Create the main TestLib library target

option(BUILD_SHARED_LIBS "build shared library or not" ON)

add_library(TestLib Helper.cpp)
target_include_directories(
    TestLib PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")

## Generate the export header for TestLib and attach it to the target

include(GenerateExportHeader)
generate_export_header(TestLib EXPORT_FILE_NAME include/TestLib/export.h)
target_compile_definitions(
    TestLib PUBLIC "$<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:TESTLIB_STATIC_DEFINE>")
message(${CMAKE_INSTALL_PREFIX})
target_include_directories(
    TestLib PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>")