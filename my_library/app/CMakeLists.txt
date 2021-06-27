

add_executable(App main.cpp)
target_compile_features(App PRIVATE cxx_std_11)

target_link_libraries(App 
	MyLibrary::wsui
	MyLibrary::wsa
	)