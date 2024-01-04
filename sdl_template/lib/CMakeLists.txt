set(IMGUI_PATH ./imgui)

file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)

add_library(ImGui STATIC ${IMGUI_SOURCES} imgui/backends/imgui_impl_sdl2.cpp imgui/backends/imgui_impl_opengl3.cpp)

target_link_libraries(ImGui PRIVATE 
	SDL2::SDL2
)

target_include_directories(ImGui PUBLIC ${IMGUI_PATH} ${IMGUI_PATH}/backends)


