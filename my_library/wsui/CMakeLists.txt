
project(wsui VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "Generated Files")
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB HEADERS_FILES ${PROJECT_SOURCE_DIR}/headers/*.h)
file(GLOB SOURCES_FILES ${PROJECT_SOURCE_DIR}/sources/*.cpp)
file(GLOB FORMS_FILES ${PROJECT_SOURCE_DIR}/sources/*.ui)
file(GLOB RESOURCES_FILES ${PROJECT_SOURCE_DIR}/*.qrc)
qt5_wrap_ui(${PROJECT_NAME}_UI_CXX ${FORMS_FILES})
add_library(${PROJECT_NAME} SHARED)
add_library(${LIB_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
string(TOUPPER ${PROJECT_NAME} VISUAL_LIBNAME)
target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE
    -D${VISUAL_LIBNAME}_LIBRARY
)
target_include_directories(${PROJECT_NAME}
        PUBLIC
            $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/headers>
        PRIVATE
	$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
        )
target_sources(${PROJECT_NAME} 
    PUBLIC
    PRIVATE 
    ${HEADERS_FILES}
    ${SOURCES_FILES} 
    ${FORMS_FILES}
    ${RESOURCES_FILES}
    ${${PROJECT_NAME}_UI_CXX}
    )
target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
    Qt5::Core
    Qt5::Widgets
    )

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)


configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/config.cmake.in
    ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    @ONLY
)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/headers/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        )

install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        )

export(
        TARGETS ${PROJECT_NAME}
        NAMESPACE ${LIB_NAME}::
        FILE ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Targets.cmake
    )

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )
install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${LIB_NAME}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        )

