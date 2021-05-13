


cmake_minimum_required(VERSION 3.3)
project( Convex_Hull VERSION 1.0)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} include)
set(CMAKE_BUILD_TYPE Release)


# CGAL and its components
find_package( CGAL QUIET COMPONENTS  )

if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()


# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )

  message(STATUS "This project requires the Boost library, and will not be compiled.")

  return()  

endif()


set(SOURCES src/main.cpp src/ConvexHull.cpp src/FileManager.cpp src/ImageGenerator.cpp)
file(GLOB SOURCES_EXE "src/*.cpp")
add_compile_options("-W" "-Wall" "-pedantic")
add_executable(exe ${SOURCES_EXE})
add_to_cached_list( CGAL_EXECUTABLE_TARGETS exe )

# Link the executable to CGAL and third-party libraries
target_link_libraries(exe PRIVATE CGAL::CGAL ${OpenCV_LIBS} )
