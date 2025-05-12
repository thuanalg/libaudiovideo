cmake_minimum_required(VERSION 3.15)
project(libaudiovideo_project)

# === Sources ===
set(SOURCE_LIB_MODULE_FILES src/libaudiovideo.c)
set(SOURCE_TEST_MODULE_FILES tests/console/main.c)



# === Include main headers ===
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# === Define shared library ===
add_library(libaudiovideo SHARED ${SOURCE_LIB_MODULE_FILES})

# === Platform-specific defines ===
if(DEFINED UNIX_LINUX)
	target_compile_definitions(libaudiovideo PUBLIC UNIX_LINUX=1)
#	if(DEFINED MACOSX)
#		target_compile_definitions(libaudiovideo PUBLIC __MACH__=1)
#	else()
#		target_compile_definitions(libaudiovideo PUBLIC __SPSR_EPOLL__=1)
#	endif()
	set_target_properties(libaudiovideo PROPERTIES VERSION 1.0.0 SOVERSION 1)
else()
	target_compile_definitions(libaudiovideo PUBLIC EXPORT_DLL_API_LIBAUDIOVIDEO=1)
	target_compile_definitions(libaudiovideo PUBLIC _CRT_SECURE_NO_WARNINGS=1)
endif()

# === Link SimpleLog if not in embedded environment ===
if(NOT DEFINED META_OPENEMBEDDED)
	if(DEFINED HEADER_SIMPLELOG)
		message(STATUS "Using SimpleLog header at: ${HEADER_SIMPLELOG}")
		target_include_directories(libaudiovideo PUBLIC "${HEADER_SIMPLELOG}")
	else()
		message(FATAL_ERROR
			"\n[SimpleLog Missing]\n"
			"HEADER_SIMPLELOG is not defined.\n"
			"Please install SimpleLog-Topic from: https://github.com/thuanalg/simplelog-topic\n"
			"Then pass the header path using:\n"
			"  -DHEADER_SIMPLELOG=/path/to/simplelog/include"
		)
	endif()

	if(DEFINED LIB_PATH_SIMPLELOG)
		message(STATUS "Using SimpleLog library path: ${LIB_PATH_SIMPLELOG}")
		target_link_directories(libaudiovideo PUBLIC "${LIB_PATH_SIMPLELOG}")
	else()
		message(FATAL_ERROR
			"\n[SimpleLog Missing]\n"
			"LIB_PATH_SIMPLELOG is not defined.\n"
			"Please install SimpleLog-Topic from: https://github.com/thuanalg/simplelog-topic\n"
			"Then pass the library path using:\n"
			"  -DLIB_PATH_SIMPLELOG=/path/to/simplelog/lib"
		)
	endif()
endif()

# === Executable: test_libaudiovideo (pure C) ===
add_executable(test_libaudiovideo ${SOURCE_TEST_MODULE_FILES})
if(DEFINED UNIX_LINUX)
	target_compile_definitions(test_libaudiovideo PUBLIC UNIX_LINUX=1)
else()
	target_compile_definitions(test_libaudiovideo PUBLIC _CRT_SECURE_NO_WARNINGS=1 )
endif()

target_link_libraries(test_libaudiovideo 
	simplelog
	libaudiovideo
)

# === Visual Studio only: include existing .vcxproj ===
if(MSVC)
#	add_executable(testMFCSerialPort WIN32 ${SOURCE_MFC_MODULE_FILES})
#	target_compile_definitions(testMFCSerialPort PUBLIC _CRT_SECURE_NO_WARNINGS=1 _AFXDLL=1)
#	target_link_libraries(testMFCSerialPort 
#		simplelog
#		libaudiovideo
#	)	
#	# Enable MFC
#	set_target_properties(testMFCSerialPort PROPERTIES
#	    USES_MFC 2
#	)	
endif()

# === Installation section for Unix/Linux ===
if(DEFINED UNIX_LINUX)
	install(TARGETS libaudiovideo LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
	install(FILES include/libaudiovideo.h DESTINATION include)
endif()

# === Link for libaudiovideo ===
target_link_libraries(libaudiovideo 
	simplelog
)
