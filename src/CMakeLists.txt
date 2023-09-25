cmake_minimum_required(VERSION 3.15)

project(cppstreams)

set(CPPSTREAMS_SRC
			# FileStreams
			${PROJECT_NAME}/filestream.cpp
			${PROJECT_NAME}/fileinputstream.cpp
			${PROJECT_NAME}/fileoutputstream.cpp
				 	 
			${PROJECT_NAME}/abstractfilestream.cpp
			${PROJECT_NAME}/abstractfileinputstream.cpp
			${PROJECT_NAME}/abstractfileoutputstream.cpp
			 
			# SocketStreams
			${PROJECT_NAME}/socketstream.cpp
			${PROJECT_NAME}/socketinputstream.cpp
			${PROJECT_NAME}/socketoutputstream.cpp
			
			${PROJECT_NAME}/abstractsocketstream.cpp
			${PROJECT_NAME}/abstractsocketinputstream.cpp
			${PROJECT_NAME}/abstractsocketoutputstream.cpp
			 
			# BufferedStreams
			${PROJECT_NAME}/bufferedstream.cpp
			${PROJECT_NAME}/bufferedinputstream.cpp
			${PROJECT_NAME}/bufferedoutputstream.cpp
			
			${PROJECT_NAME}/abstractbufferedinputstream.cpp
			${PROJECT_NAME}/abstractbufferedoutputstream.cpp
			 
			# EncryptedStreams
			${PROJECT_NAME}/encryptedstream.cpp
			${PROJECT_NAME}/encryptedinputstream.cpp
			${PROJECT_NAME}/encryptedoutputstream.cpp
			
			${PROJECT_NAME}/abstractencryptedstream.cpp
)

set(CPPSTREAMS_HEADERS
			# Interfaces
			${PROJECT_NAME}/inputstream.h
			${PROJECT_NAME}/outputstream.h
			${PROJECT_NAME}/stream.h

			# FileStreams
			${PROJECT_NAME}/filestream.h
			${PROJECT_NAME}/fileinputstream.h
			${PROJECT_NAME}/fileoutputstream.h
				 	 
			${PROJECT_NAME}/abstractfilestream.h
			${PROJECT_NAME}/abstractfileinputstream.h
			${PROJECT_NAME}/abstractfileoutputstream.h
			 
			# SocketStreams
			${PROJECT_NAME}/socketstream.h
			${PROJECT_NAME}/socketinputstream.h
			${PROJECT_NAME}/socketoutputstream.h
			
			${PROJECT_NAME}/abstractsocketstream.h
			${PROJECT_NAME}/abstractsocketinputstream.h
			${PROJECT_NAME}/abstractsocketoutputstream.h
			 
			# BufferedStreams
			${PROJECT_NAME}/bufferedstream.h
			${PROJECT_NAME}/bufferedinputstream.h
			${PROJECT_NAME}/bufferedoutputstream.h
			
			${PROJECT_NAME}/abstractbufferedinputstream.h
			${PROJECT_NAME}/abstractbufferedoutputstream.h
			 
			# EncryptedStreams
			${PROJECT_NAME}/encryptedstream.h
			${PROJECT_NAME}/encryptedinputstream.h
			${PROJECT_NAME}/encryptedoutputstream.h
			
			${PROJECT_NAME}/abstractencryptedstream.h
)

add_library(${PROJECT_NAME} STATIC ${CPPSTREAMS_SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC cpputils)

target_compile_definitions(${PROJECT_NAME} PRIVATE -D_WIN32_WINNT=0x0601)

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(FILES ${CPPSTREAMS_HEADERS} DESTINATION ${CPPSTREAMS_INSTALL_INCLUDE}/${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME} DESTINATION ${CPPSTREAMS_INSTALL_LIB})