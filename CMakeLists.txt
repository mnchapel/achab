#CMake arguments for debug mode : -DCMAKE_BUILD_TYPE=Debug

cmake_minimum_required(VERSION 2.8)
project(achab)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
message("OPENCV include dirs  ${OpenCV_INCLUDE_DIRS}")

# add QT --------------------------
find_package(Qt5Widgets)
find_package(Qt5Gui)
#include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(${QT_INCLUDES})

# add OpenCV ----------------------
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} "src/")

set(LIBS ${LIBS}
		"opencv_core"
		"opencv_highgui"
		"opencv_ml"
		"opencv_xfeatures2d"
		"opencv_features2d"
		"opencv_flann"
		"opencv_nonfree"
		"opencv_imgproc"
		"opencv_video"
		"opencv_calib3d"
		"opencv_imgcodecs")


file(GLOB_RECURSE HDR src/*/*.h)
file(GLOB_RECURSE SRC src/*/*.cpp)
file(GLOB_RECURSE UIS src/*/*.ui)

QT5_WRAP_UI(UI ${UIS})
#foreach(moc_hdr ${UIS})
#  GET_FILENAME_COMPONENT(moc_name ${moc_hdr} NAME_WE)
#  SET (moc_out src/moc_${moc_name}.cxx)
#  QT4_GENERATE_MOC( ${moc_in} ${moc_out} )
#  LIST (APPEND MOC_SOURCES ${moc_out})
#endforeach(moc_hdr)

QT5_WRAP_CPP(HDR_MOC ${HDR})

add_executable(achab_exe ${SRC} ${HDR_MOC} ${UI})

target_link_libraries(achab_exe ${LIBS} Qt5::Widgets Qt5::Gui)
