set(SEC_LIST user_service.cc ../user.pb.cc)

add_executable(provider ${SEC_LIST})
target_link_libraries(provider morpc protobuf)