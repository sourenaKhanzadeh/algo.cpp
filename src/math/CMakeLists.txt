message("Adding Executable: Horners algo")
message("==================================")
add_executable(horner horner.cpp)
target_include_directories(horner PUBLIC ${PROJECT_SOURCE_DIR}/include)

