message("Adding Executable: insertion sort")
message("==================================")
add_executable(insertion insertion.cpp)
target_include_directories(insertion PUBLIC ${PROJECT_SOURCE_DIR}/include)


message("Adding Executable: selection sort")
message("==================================")
add_executable(selection select.cpp)
target_include_directories(selection PUBLIC ${PROJECT_SOURCE_DIR}/include)
