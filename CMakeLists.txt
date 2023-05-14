cmake_minimum_required(VERSION 3.0.0)
project(QCV VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ../output)

set(libs )
set(src )

set(OpenCV_DIR "/e/QDWorkplace/package/opencv-3.4.16/output_ubuntu2004_debug/share/OpenCV/")
find_package(OpenCV REQUIRED) 

include_directories(./)
# test 
aux_source_directory(./test/ SRC_LIST)

# QAlgo
aux_source_directory(./QAlgo/ SRC_LIST)

set(src main.cpp ${SRC_LIST})
set(libs ${OpenCV_LIBS})

add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} ${libs})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
