cmake_minimum_required(VERSION 3.1 )

project(csv_parser)
set(ROOT_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${ROOT_PATH}/common_cmake)
include(common)

#set(USE_PAIRING ON)
add_source_files(${ROOT_PATH}/src *.cpp CPP_FILES)
add_source_files(${ROOT_PATH}/src *.h* CPP_FILES)
add_source_files(${ROOT_PATH}/include *.h* CPP_FILES)


add_executable(${PROJECT_NAME} main.cpp ${CPP_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${ROOT_PATH}/src)
target_include_directories(${PROJECT_NAME} PRIVATE ${ROOT_PATH}/include)

target_link_libraries(
    ${PROJECT_NAME} 
    ${common_depend_libs}
)

