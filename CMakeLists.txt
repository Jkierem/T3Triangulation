project( T3Triangulation )

cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

find_package( CGAL QUIET COMPONENTS  )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)
include(${CGAL_USE_FILE} ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLU_INCLUDE_DIRS})
add_executable(triangulation main.cxx ./src/GEngine/GEngine.cxx ./src/Core/Core.hxx)

target_link_libraries(triangulation ${CGAL_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLU_LIBRARIES})
