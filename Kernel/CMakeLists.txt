target_sources( ${PROJECT_NAME}
	INTERFACE
		"${CMAKE_CURRENT_LIST_DIR}/Version.hpp"
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/Barrier.hpp"
		"${CMAKE_CURRENT_LIST_DIR}/ConditionVariable.hpp"
		"${CMAKE_CURRENT_LIST_DIR}/MemoryPartition.hpp"
		"${CMAKE_CURRENT_LIST_DIR}/Mutex.hpp"
		"${CMAKE_CURRENT_LIST_DIR}/RWLock.hpp"
		"${CMAKE_CURRENT_LIST_DIR}/Spinlock.hpp"
		"${CMAKE_CURRENT_LIST_DIR}/Thread.hpp"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Main.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/Barrier.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/ConditionVariable.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/MemoryPartition.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/Mutex.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/RWLock.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/Spinlock.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/Thread.cpp"
)

# Generate version header 
configure_file( "${CMAKE_CURRENT_LIST_DIR}/Version.hpp.in" "Include/Version.hpp" )