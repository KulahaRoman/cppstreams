cmake_minimum_required(VERSION 3.15)

project(cppstreams-test)

set(CPPSTREAMS_TEST_SRC	main.cpp
						src/filestreamtest.cpp
)

add_executable(${PROJECT_NAME} ${CPPSTREAMS_TEST_SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC cppstreams)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest)

config_compiler_and_linker()

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE "/EHsc")
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CPPSTREAMS_INSTALL_BIN})