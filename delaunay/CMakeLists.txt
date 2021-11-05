# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

cmake_minimum_required(VERSION 3.1...3.15)

project( your_program  delaunay.cpp)


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

# include for local directory
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIRS})
# include for local package


# Creating entries for target: your_program
# ############################

add_executable( your_program  delaunay.cpp )

add_to_cached_list( CGAL_EXECUTABLE_TARGETS your_program delaunay.cpp )
# cmake -D CMAKE_C_COMPILER="/Library/Developer/CommandLineTools/usr/bin/c++" -D CMAKE_CXX_COMPILER "/Library/Developer/CommandLineTools/usr/bin/cc" /Users/diegovelazquez/Documents/GitHub/TC2038/delaunay
# Link the executable to CGAL and third-party libraries
find_package(OpenGL REQUIRED)

target_link_libraries(
  delauney
  PRIVATE
  CGAL :: CGAL
  ${OPENGL_LIBRARIES}
  GLUT :: GLUT

)