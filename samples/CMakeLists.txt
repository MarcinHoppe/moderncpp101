cmake_minimum_required (VERSION 3.6)

project(moderncpp101_samples)

include_directories( ..\\include )

add_subdirectory(concurrency)
add_subdirectory(res_mgmt)

add_executable(algorithms_intro algorithms_intro.cpp)
add_executable(exceptions exceptions.cpp)
add_executable(find_all find_all.cpp)
add_executable(hashtable hashtable.cpp)
add_executable(lists lists.cpp)
add_executable(map map.cpp)
add_executable(optional optional.cpp)
add_executable(predicates predicates.cpp)
add_executable(regex regex.cpp)
add_executable(text text.cpp)
add_executable(tokenize tokenize.cpp)
add_executable(tuples tuples.cpp)
add_executable(vector vector.cpp)