cmake_minimum_required(VERSION 3.5)
project(MyLibrary VERSION 1.0.0 LANGUAGES CXX)

set(LIB_NAME ${PROJECT_NAME} CACHE STRING "lib name")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/libconfig.cmake.in
    ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    @ONLY
)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        )
add_subdirectory("wsui")
add_subdirectory("wsa")
add_subdirectory("app")

