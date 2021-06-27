cmake_minimum_required(VERSION 3.5)
project(App VERSION 1.0.0 LANGUAGES CXX)
set(MyLibrary_DIR "C:\\visual\\modern_cmake_example-master\\my_library\\build")

find_package(MyLibrary 
	COMPONENTS
	wsui 
	wsa
	REQUIRED
	)
#find_package(wsui COMPONENTS abd REQUIRED)

add_executable(App main.cpp)
target_compile_features(App PRIVATE cxx_std_11)

target_link_libraries(App 
	MyLibrary::wsui
	MyLibrary::wsa
	)