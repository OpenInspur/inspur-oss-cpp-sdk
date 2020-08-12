project(cpp-sdk-Demo)
	
file(GLOB Demo_src "src/*")



add_executable(${PROJECT_NAME} 
	${Demo_src} )

target_include_directories(${PROJECT_NAME}
	PRIVATE ${CMAKE_SOURCE_DIR}/sdk/include)

target_link_libraries(${PROJECT_NAME} cpp-sdk)	
target_link_libraries(${PROJECT_NAME} ${CRYPTO_LIBS})
target_link_libraries(${PROJECT_NAME} ${CLIENT_LIBS})
if (${TARGET_OS} STREQUAL "LINUX")
target_link_libraries(${PROJECT_NAME} pthread)	
endif()

target_compile_options(${PROJECT_NAME} 
	PRIVATE "${SDK_COMPILER_FLAGS}")

install(TARGETS  ${PROJECT_NAME}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	)