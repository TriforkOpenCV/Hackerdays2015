cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
add_executable( DisplayImage DisplayImage.cpp LineExtractor.cpp LineDetector.cpp CornerDetector.cpp DetectedLine.cpp CornerHistogramAnalyzer.cpp)
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
