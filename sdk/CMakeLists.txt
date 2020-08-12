

project(cpp-sdk)


#common header
file(GLOB sdk_auth_header "include/inspurcloud/oss/auth/*.h")
file(GLOB sdk_client_header "include/inspurcloud/oss/client/*.h")	
file(GLOB sdk_http_header "include/inspurcloud/oss/http/*.h")
file(GLOB sdk_utils_header "include/inspurcloud/oss/utils/*.h")
file(GLOB sdk_model_header "include/inspurcloud/oss/model/*.h")	
file(GLOB sdk_public_header "include/inspurcloud/oss/*.h")	

#all header
file(GLOB sdk_header
	${sdk_auth_header}
	${sdk_client_header}
	${sdk_http_header}
	${sdk_utils_header}
	${sdk_model_header}
    ${sdk_public_header}
)

#common source
file(GLOB sdk_auth_src "src/auth/*.cc")
file(GLOB sdk_client_src "src/client/*.cc")
file(GLOB sdk_http_src "src/http/*.cc")
file(GLOB sdk_utils_src "src/utils/*.cc")
file(GLOB sdk_model_src "src/model/*.cc")
file(GLOB sdk_public_src "src/*.cc")

#external source
file(GLOB sdk_external_json_src "src/external/json/*.cpp")
file(GLOB sdk_external_tinnyxml2_src "src/external/tinyxml2/*.cpp")

#all source
file(GLOB sdk_src
	${sdk_auth_src}
	${sdk_client_src}
	${sdk_http_src}
	${sdk_utils_src}
	${sdk_model_src}
    ${sdk_public_src}
    ${sdk_external_json_src}
    ${sdk_external_tinnyxml2_src}
)

#extra define pass to source code
if (BUILD_TESTS)
	set(EXTRA_DEFINE "-DENABLE_OSS_TEST")
else()
	set(EXTRA_DEFINE "")
endif()
	
#static lib
add_library(${PROJECT_NAME}${STATIC_LIB_SUFFIX} STATIC
	${sdk_header}
	${sdk_src})
	
set_target_properties(${PROJECT_NAME}${STATIC_LIB_SUFFIX}
	PROPERTIES
	LINKER_LANGUAGE CXX
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
	OUTPUT_NAME ${TARGET_OUTPUT_NAME_PREFIX}${PROJECT_NAME}${STATIC_LIB_SUFFIX}
	)

target_include_directories(${PROJECT_NAME}${STATIC_LIB_SUFFIX}
	PRIVATE include
	PRIVATE include/inspurcloud/oss	
	PRIVATE src/external/)

target_include_directories(${PROJECT_NAME}${STATIC_LIB_SUFFIX}
	PRIVATE ${CRYPTO_INCLUDE_DIRS}
	PRIVATE ${CLIENT_INCLUDE_DIRS})

target_compile_options(${PROJECT_NAME}${STATIC_LIB_SUFFIX} 
	PRIVATE "${SDK_COMPILER_FLAGS}" "${EXTRA_DEFINE}")

#shared lib
if (BUILD_SHARED_LIBS)
	add_library(${PROJECT_NAME} SHARED
		${sdk_header}
		${sdk_src})
	
	set_target_properties(${PROJECT_NAME}
		PROPERTIES
		LINKER_LANGUAGE CXX
		ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		OUTPUT_NAME ${TARGET_OUTPUT_NAME_PREFIX}${PROJECT_NAME}
		)
	
	target_include_directories(${PROJECT_NAME}
		PRIVATE include
		PRIVATE include/inspurcloud/oss	
		PRIVATE src/external/)
	
	target_include_directories(${PROJECT_NAME}
		PRIVATE ${CRYPTO_INCLUDE_DIRS}
		PRIVATE ${CLIENT_INCLUDE_DIRS})

	target_compile_options(${PROJECT_NAME} 
		PRIVATE "${SDK_COMPILER_FLAGS}" -DInspurCLOUD_SHARED -DInspurCLOUD_OSS_LIBRARY)
	
	if(NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	target_compile_options(${PROJECT_NAME} 
		PRIVATE "-fvisibility=hidden")
	endif()

	target_link_libraries(${PROJECT_NAME} ${CRYPTO_LIBS})
	target_link_libraries(${PROJECT_NAME} ${CLIENT_LIBS})	
endif()

#install 
install(FILES ${sdk_auth_header}
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/inspurcloud/oss/auth)
install(FILES ${sdk_client_header}
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/inspurcloud/oss/client)
install(FILES ${sdk_http_header}
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/inspurcloud/oss/http)
install(FILES ${sdk_utils_header}
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/inspurcloud/oss/utils)
install(FILES ${sdk_model_header}
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/inspurcloud/oss/model)
install(FILES ${sdk_public_header}
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/inspurcloud/oss)

install(TARGETS  ${PROJECT_NAME}${STATIC_LIB_SUFFIX}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	)

if (BUILD_SHARED_LIBS)
install(TARGETS  ${PROJECT_NAME}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	)
endif()