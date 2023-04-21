set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
set(COMMONAPI_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/libs/capicxx-core-runtime/include")
set(COMMON_SOMEIP_INC_DIR "${CMAKE_SOURCE_DIR}/libs/capicxx-someip-runtime/include")
set(VSOMEIP_INC_DIR "${CMAKE_SOURCE_DIR}/libs/vsomeip/interface/")
set(CRYPTO_INCLUDE_DIRS  "${CMAKE_SOURCE_DIR}/libs/cryptoHandler/include"
                         "${CMAKE_SOURCE_DIR}/libs/libsodium/src/libsodium/include"
                         "${CMAKE_SOURCE_DIR}/libs/libsodium/src/libsodium/include/sodium"
                         "${CMAKE_SOURCE_DIR}/build/libsodium/generated/")
set(LOG4CPLUS_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/libs/log4cplus/include")
                
message(${CMAKE_SOURCE_DIR}/libs/capicxx-core-runtime/include)

set(STUB_DIR "${CMAKE_SOURCE_DIR}/build/src-gen")
set(LIBRARY "${CMAKE_SOURCE_DIR}/build/libs")

add_executable(secureServer serverMain.cpp
                            server.cpp
                            ${STUB_DIR}/v1/secureMessageTransfer/ServerSomeIPStubAdapter.cpp
                            ${STUB_DIR}/v1/secureMessageTransfer/ServerSomeIPDeployment.cpp)

target_link_directories(
                secureServer PUBLIC
                ${LIBRARY}/capicxx-core-runtime
                ${LIBRARY}/capicxx-someip-runtime
                ${LIBRARY}/libsodium
                ${LIBRARY}/log4cplus
                )

target_link_libraries(secureServer CommonAPI CommonAPI-SomeIP vsomeip3 cryptoHandler log4cplus)

target_include_directories(secureServer PUBLIC
                                        ../include
                                        ${COMMONAPI_INCLUDE_DIRS}
                                        ${COMMON_SOMEIP_INC_DIR}
                                        ${VSOMEIP_INC_DIR}
                                        ${CRYPTO_INCLUDE_DIRS}
                                        ${STUB_DIR}
                                        ${LOG4CPLUS_INCLUDE_DIRS})
                                        
install(TARGETS secureServer DESTINATION bin)