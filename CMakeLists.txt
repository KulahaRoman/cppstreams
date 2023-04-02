cmake_minimum_required(VERSION 3.8)

project(cppstreams)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPPSTREAMS_SRC # FileStreams
			src/${PROJECT_NAME}/filestreams/filestream.cpp
			src/${PROJECT_NAME}/filestreams/fileinputstream.cpp
			src/${PROJECT_NAME}/filestreams/fileoutputstream.cpp
					 	 
			src/${PROJECT_NAME}/filestreams/abstracts/abstractfilestream.cpp
			src/${PROJECT_NAME}/filestreams/abstracts/abstractfileinputstream.cpp
			src/${PROJECT_NAME}/filestreams/abstracts/abstractfileoutputstream.cpp
			 
			# SocketStreams
			src/${PROJECT_NAME}/socketstreams/socketstream.cpp
			src/${PROJECT_NAME}/socketstreams/socketinputstream.cpp
			src/${PROJECT_NAME}/socketstreams/socketoutputstream.cpp
			
			src/${PROJECT_NAME}/socketstreams/abstracts/abstractsocketstream.cpp
			src/${PROJECT_NAME}/socketstreams/abstracts/abstractsocketinputstream.cpp
			src/${PROJECT_NAME}/socketstreams/abstracts/abstractsocketoutputstream.cpp
			 
			# BufferedStreams
			src/${PROJECT_NAME}/bufferedstreams/bufferedstream.cpp
			src/${PROJECT_NAME}/bufferedstreams/bufferedinputstream.cpp
			src/${PROJECT_NAME}/bufferedstreams/bufferedoutputstream.cpp
			
			src/${PROJECT_NAME}/bufferedstreams/abstracts/abstractbufferedinputstream.cpp
			src/${PROJECT_NAME}/bufferedstreams/abstracts/abstractbufferedoutputstream.cpp
			 
			# EncryptedStreams
			src/${PROJECT_NAME}/encryptedstreams/encryptedstream.cpp
			src/${PROJECT_NAME}/encryptedstreams/encryptedinputstream.cpp
			src/${PROJECT_NAME}/encryptedstreams/encryptedoutputstream.cpp
			
			src/${PROJECT_NAME}/encryptedstreams/abstracts/abstractencryptedstream.cpp
)

add_library(${PROJECT_NAME} STATIC ${CPPSTREAMS_SRC})

target_compile_definitions(${PROJECT_NAME} PRIVATE -D_WIN32_WINNT=0x0601)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})

add_subdirectory(libs/cpputils)
target_link_libraries(${PROJECT_NAME} PUBLIC cpputils)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")