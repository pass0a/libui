#cmake file for project association
#author: liuwenjun
#created:2014/02/20

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

## 添加项目
set(CMAKE_SHARED_LIBRARY_SUFFIX ".passoa")
SET(CMAKE_SHARED_LIBRARY_PREFIX "")

include_directories(${PROJECT_SOURCE_DIR}/stage)
LINK_DIRECTORIES (${PROJECT_SOURCE_DIR}/stage)

add_library(ui SHARED
	${PROJECT_SOURCE_DIR}/src/index.cpp
	${PROJECT_SOURCE_DIR}/src/binding.cpp
	${PROJECT_SOURCE_DIR}/src/export.def
	${PROJECT_SOURCE_DIR}/src/plugin.h
	)
ADD_EXECUTABLE(uitest ${PROJECT_SOURCE_DIR}/test/index.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ui "libui")
target_link_libraries(uitest "libui")
install(TARGETS ui RUNTIME DESTINATION node_modules/libui)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/modules/stage/ DESTINATION node_modules/libui)
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/test/ DESTINATION test)
