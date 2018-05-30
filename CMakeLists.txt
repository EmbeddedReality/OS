project( CausalityOS CXX )

add_library( ${PROJECT_NAME} STATIC "" )

set( OS_VERSION_MAJOR 0 )
set( OS_VERSION_MINOR 1 )
set( OS_VERSION_PATCH 0 )

include( Include/CMakeLists.txt )
include( Kernel/CMakeLists.txt )

# -- Compiler configuration ------------------------------
if( CMAKE_COMPILER_IS_GNUCXX )
	if( CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0) 
		message( FATAL_ERROR "${PROJECT_NAME} requires C++14. G++ must be 5.0 or later, the used version is ${CMAKE_CXX_COMPILER_VERSION}" )
	else()
	 	# C++14 Support
		message( STATUS "Using C++14" ) 
		target_compile_options( ${PROJECT_NAME} PUBLIC -std=c++14 )

		# CXX Flags
		target_compile_options( ${PROJECT_NAME} PUBLIC -Wall -Wno-deprecated -Wno-write-strings )
		
		# Setup shared libraries linker flags
		set( CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined" )
	
		# check platform (32bit / 64bit) 
		if( CMAKE_SIZEOF_VOID_P EQUAL 8 ) 
			message( STATUS "Checking platform: 64-bit" ) 
			target_compile_options( ${PROJECT_NAME} PUBLIC -m64 ) 
		else() 
			message( STATUS "Checking platform: 32-bit") 
		endif() 
	endif()
else()
	message( FATAL_ERROR "Unsupported compiler detected." )
endif( CMAKE_COMPILER_IS_GNUCXX )

#set_target_properties( ${PROJECT_NAME} 
#	PROPERTIES 
#		VERSION ${${PROJECT_NAME}_VERSION} 
#		SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
#		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
#)

#target_link_libraries( ${PROJECT_NAME} 
# Add here
#)