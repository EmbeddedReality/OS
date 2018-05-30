target_sources( ${PROJECT_NAME}
	INTERFACE
		"${CMAKE_CURRENT_LIST_DIR}/pthread.h"
		"${CMAKE_CURRENT_LIST_DIR}/sched.h"
		"${CMAKE_CURRENT_LIST_DIR}/time.h"
		"${CMAKE_CURRENT_LIST_DIR}/fake.h"
	PUBLIC
#		"${CMAKE_CURRENT_LIST_DIR}/Sample.hpp"
	PRIVATE
#		"${CMAKE_CURRENT_LIST_DIR}/Main.cpp"
)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/Include )
include_directories( ${CMAKE_CURRENT_BINARY_DIR}/Include )