add_library(cryptoHandler keyHandler.cpp)

target_include_directories(cryptoHandler PUBLIC 
                                        ${CMAKE_CURRENT_SOURCE_DIR}/../../../build/libs/libsodium/generated/sodium
                                        ${CMAKE_CURRENT_SOURCE_DIR}/../../libsodium/src/libsodium/include
                                        ${CMAKE_CURRENT_SOURCE_DIR}/../../libsodium/src/libsodium/include/sodium
                                        ${CMAKE_CURRENT_SOURCE_DIR}/../include)

message(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cryptoHandler PUBLIC sodium)

install(TARGETS cryptoHandler DESTINATION lib)