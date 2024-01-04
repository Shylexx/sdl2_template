option(USE_SDL_SYS "Use System installed Version of SDL2 installed via Package Manager/SDL2_DIR Var" OFF)

if(USE_SDL_SYS)
	message(STATUS "Using System Installed SDL2")
	find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
	find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
else()
	message(STATUS "Using Git Submodule Copy of SDL2")
	add_subdirectory(lib/SDL2 EXCLUDE_FROM_ALL)
endif()


add_subdirectory(lib/glad)
add_subdirectory(lib/glm)

# imgui cmake in base lib dir
add_subdirectory(lib)

add_executable(${PROJECT_NAME}
	src/Main.cpp
)

if(TARGET SDL2::SDL2main)
	message(STATUS "SDL2main Found!")
	target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE "/EHsc")
endif()

target_include_directories(${PROJECT_NAME} 
	PRIVATE
	src
	lib/stb_image
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
	SDL2::SDL2
	#SDL2_image::SDL2_image
	#SDL2_mixer::SDL2_mixer
	#SDL2_ttf::SDL2_ttf
	glad
	glm::glm
	ImGui
)

# Copy all DLLS to the bin folder to run the application :]
# includes SDL2 on windows and assimp on both
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND_EXPAND_LISTS
)
