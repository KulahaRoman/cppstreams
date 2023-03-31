cmake_minimum_required(VERSION 3.8)

project(cppstreams)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES # FileStreams
			src/cppstreams/filestreams/filestream.cpp
			src/cppstreams/filestreams/fileinputstream.cpp
			src/cppstreams/filestreams/fileoutputstream.cpp
					 	 
			src/cppstreams/filestreams/abstracts/abstractfilestream.cpp
			src/cppstreams/filestreams/abstracts/abstractfileinputstream.cpp
			src/cppstreams/filestreams/abstracts/abstractfileoutputstream.cpp
			 
			# SocketStreams
			src/cppstreams/socketstreams/socketstream.cpp
			src/cppstreams/socketstreams/socketinputstream.cpp
			src/cppstreams/socketstreams/socketoutputstream.cpp
			
			src/cppstreams/socketstreams/abstracts/abstractsocketstream.cpp
			src/cppstreams/socketstreams/abstracts/abstractsocketinputstream.cpp
			src/cppstreams/socketstreams/abstracts/abstractsocketoutputstream.cpp
			 
			# BufferedStreams
			src/cppstreams/bufferedstreams/bufferedstream.cpp
			src/cppstreams/bufferedstreams/bufferedinputstream.cpp
			src/cppstreams/bufferedstreams/bufferedoutputstream.cpp
			
			src/cppstreams/bufferedstreams/abstracts/abstractbufferedinputstream.cpp
			src/cppstreams/bufferedstreams/abstracts/abstractbufferedoutputstream.cpp
			 
			# EncryptedStreams
			src/cppstreams/encryptedstreams/encryptedstream.cpp
			src/cppstreams/encryptedstreams/encryptedinputstream.cpp
			src/cppstreams/encryptedstreams/encryptedoutputstream.cpp
			
			src/cppstreams/encryptedstreams/abstracts/abstractencryptedstream.cpp
)

set(BOOST_ROOT C:/Boost)

find_package(Boost REQUIRED)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON)

if(NOT TARGET ${PROJECT_NAME})
  add_library(${PROJECT_NAME} STATIC ${SOURCES})

  target_compile_definitions(${PROJECT_NAME} PRIVATE -D_WIN32_WINNT=0x0601)

  add_subdirectory(libs/cpputils)
  target_link_libraries(${PROJECT_NAME} PUBLIC cpputils)

  target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
  target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()