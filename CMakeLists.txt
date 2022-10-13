cmake_minimum_required(VERSION 3.8)

project(cppstreams)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES # Streams
			src/cppstreams/streams.cpp
			 
			# FileStreams
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

set(HEADERS # Interfaces
			src/cppstreams/stream.h
			src/cppstreams/inputstream.h
			src/cppstreams/outputstream.h
			 
			# Streams
			src/cppstreams/streams.h
			 
			# FileStreams
			src/cppstreams/filestreams/filestream.h
			src/cppstreams/filestreams/fileinputstream.h
			src/cppstreams/filestreams/fileoutputstream.h
	 	 
			src/cppstreams/filestreams/abstracts/abstractfilestream.h
			src/cppstreams/filestreams/abstracts/abstractfileinputstream.h
			src/cppstreams/filestreams/abstracts/abstractfileoutputstream.h
			 
			# SocketStreams
			src/cppstreams/socketstreams/socketstream.h
			src/cppstreams/socketstreams/socketinputstream.h
			src/cppstreams/socketstreams/socketoutputstream.h
			
			src/cppstreams/socketstreams/abstracts/abstractsocketstream.h
			src/cppstreams/socketstreams/abstracts/abstractsocketinputstream.h
			src/cppstreams/socketstreams/abstracts/abstractsocketoutputstream.h
			 
			# BufferedStreams
			src/cppstreams/bufferedstreams/bufferedstream.h
			src/cppstreams/bufferedstreams/bufferedinputstream.h
			src/cppstreams/bufferedstreams/bufferedoutputstream.h
			
			src/cppstreams/bufferedstreams/abstracts/abstractbufferedinputstream.h
			src/cppstreams/bufferedstreams/abstracts/abstractbufferedoutputstream.h
			 
			# EncryptedStreams
			src/cppstreams/encryptedstreams/encryptedstream.h
			src/cppstreams/encryptedstreams/encryptedinputstream.h
			src/cppstreams/encryptedstreams/encryptedoutputstream.h
			
			src/cppstreams/encryptedstreams/abstracts/abstractencryptedstream.h
)

set(BOOST_ROOT D:/Development/CXX/Libraries/Boost)

find_package(Boost REQUIRED)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

add_subdirectory(libs/cpputils)
target_link_libraries(${PROJECT_NAME} PUBLIC cpputils)

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")