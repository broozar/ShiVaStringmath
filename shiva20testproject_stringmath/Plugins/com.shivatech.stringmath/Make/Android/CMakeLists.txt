
# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.
cmake_minimum_required(VERSION 3.4.3)

project(StringMath C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(SRCROOT             "../../Sources" )
set(FRAMEWORKSROOT      "../../Frameworks/Android" )


set(COMMON_C_FLAGS	"-Oz -Wno-unknown-pragmas -fPIC -fsigned-char -fno-strict-aliasing -fno-short-enums -fno-exceptions -D__ANDROID__ -DANDROID_NDK -DANDROID -DRELEASE -D_GNU_SOURCE -DHAVE_STDINT_H" )

if( ANDROID_ABI STREQUAL "armeabi")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   ${COMMON_C_FLAGS} -march=armv5te -msoft-float")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} ${COMMON_C_FLAGS} -march=armv5te -msoft-float -fno-rtti ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS} -march=armv5te -msoft-float -fno-rtti ")
set(BUILT_PRODUCTS_DIR "../../../Contents/Android/arm_v5te")

elseif( ANDROID_ABI STREQUAL "armeabi-v7a")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   ${COMMON_C_FLAGS} -march=armv7-a -mfloat-abi=softfp -mfpu=vfp")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} ${COMMON_C_FLAGS} -march=armv7-a -mfloat-abi=softfp -mfpu=vfp -fno-rtti ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS} -march=armv7-a -mfloat-abi=softfp -mfpu=vfp -fno-rtti ")
set(BUILT_PRODUCTS_DIR "../../../Contents/Android/arm_v7a")

elseif( ANDROID_ABI STREQUAL "arm64-v8a")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   ${COMMON_C_FLAGS} -march=armv8-a -mfloat-abi=softfp -mfpu=vfp")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} ${COMMON_C_FLAGS} -march=armv8-a -mfloat-abi=softfp -mfpu=vfp -fno-rtti ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS} -march=armv8-a -mfloat-abi=softfp -mfpu=vfp -fno-rtti ")
set(BUILT_PRODUCTS_DIR "../../../Contents/Android/arm_v8a")

elseif( ANDROID_ABI STREQUAL "x86")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   ${COMMON_C_FLAGS} ")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} ${COMMON_C_FLAGS} ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS} ")

string(REPLACE "-mstackrealign" "" CMAKE_C_FLAGS   ${CMAKE_C_FLAGS}   )
string(REPLACE "-mstackrealign" "" CMAKE_CPP_FLAGS ${CMAKE_CPP_FLAGS} )
string(REPLACE "-mstackrealign" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

set(BUILT_PRODUCTS_DIR "../../../Contents/Android/x86_32")
endif()


# List of source files
file(GLOB_RECURSE source_files "${SRCROOT}/*.c*" )
foreach(__i ${source_files})
	if(${__i} MATCHES ".*[\\\/]Platforms[\\\/].*")
		list(REMOVE_ITEM source_files ${__i})
	endif()
endforeach()
file(GLOB_RECURSE source_platform_files "${SRCROOT}/Platforms/Android/*.c*" )


# set project path
include_directories("${FRAMEWORKSROOT}/include" "${SRCROOT}" "${SRCROOT}/Platforms/Android" "${SRCROOT}/S3DX")


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

add_library( # Sets the name of the library.
             StringMath

             # Sets the library as a shared library.
             STATIC

             # Provides a relative path to your source file(s).
             ${source_files}
			 ${source_platform_files}
			)
			
set_target_properties(StringMath  PROPERTIES 
						PREFIX "" 
						ARCHIVE_OUTPUT_DIRECTORY ${BUILT_PRODUCTS_DIR} )

		
#copy frameworks libs and binaries
if( ANDROID_ABI STREQUAL "armeabi")
file(GLOB_RECURSE frameworks_static_lib "${FRAMEWORKSROOT}/arm_v5te/lib/*.a" )
file(GLOB_RECURSE frameworks_bin "${FRAMEWORKSROOT}/arm_v5te/bin/*.*" )
file(COPY ${frameworks_static_lib} DESTINATION "${BUILT_PRODUCTS_DIR}/")
file(COPY ${frameworks_bin} DESTINATION "${BUILT_PRODUCTS_DIR}/")

elseif( ANDROID_ABI STREQUAL "armeabi-v7a")
file(GLOB_RECURSE frameworks_static_lib "${FRAMEWORKSROOT}/arm_v7a/lib/*.a" )
file(GLOB_RECURSE frameworks_bin "${FRAMEWORKSROOT}/arm_v7a/bin/*.*" )
file(COPY ${frameworks_static_lib} DESTINATION "${BUILT_PRODUCTS_DIR}/")
file(COPY ${frameworks_bin} DESTINATION "${BUILT_PRODUCTS_DIR}/")

elseif( ANDROID_ABI STREQUAL "arm64-v8a")
file(GLOB_RECURSE frameworks_static_lib "${FRAMEWORKSROOT}/arm64-v8a/lib/*.a" )
file(GLOB_RECURSE frameworks_bin "${FRAMEWORKSROOT}/arm64-v8a/bin/*.*" )
file(COPY ${frameworks_static_lib} DESTINATION "${BUILT_PRODUCTS_DIR}/")
file(COPY ${frameworks_bin} DESTINATION "${BUILT_PRODUCTS_DIR}/")

elseif( ANDROID_ABI STREQUAL "x86")
file(GLOB_RECURSE frameworks_static_lib "${FRAMEWORKSROOT}/x86_32/lib/*.a" )
file(GLOB_RECURSE frameworks_bin "${FRAMEWORKSROOT}/x86_32/bin/*.*" )
file(COPY ${frameworks_static_lib} DESTINATION "${BUILT_PRODUCTS_DIR}/")
file(COPY ${frameworks_bin} DESTINATION "${BUILT_PRODUCTS_DIR}/")

endif()

