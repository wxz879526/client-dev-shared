cmake_minimum_required(VERSION 3.7)

project(HelloWorld)

enable_testing()

add_subdirectory(TestLib)

add_executable(${PROJECT_NAME} HelloWorld.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC TestLib)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/TestLib ${PROJECT_BINARY_DIR}/TestLib/include)
install(TARGETS ${PROJECT_NAME} TestLib 
    RUNTIME DESTINATION sdk/bin
	ARCHIVE DESTINATION sdk/lib
)

add_test(demo_test_2_add_3 ${PROJECT_NAME} 2 3)
set_tests_properties(demo_test_2_add_3 PROPERTIES PASS_REGULAR_EXPRESSION "5")

add_test(demo_test_8_add_3 ${PROJECT_NAME} 8 3)
set_tests_properties(demo_test_8_add_3 PROPERTIES PASS_REGULAR_EXPRESSION "10")

set(CPACK_GENERATOR NSIS)
set(CPACK_PACKAGE_NAME "TestLib")
set(CPACK_PACKAGE_VENDOR "test.org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyDemo - Demo Example")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPack Example")
SET(CPACK_NSIS_MODIFY_PATH ON)

INCLUDE(CPack)