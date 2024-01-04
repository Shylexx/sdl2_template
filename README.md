# SDL2 CMake Template

A quickstart template for a CMake project intended for games/graphics

Includes Git Submodules for
- ImGui (defaults to OpenGL3 Backend)
- GLM
- SDL2

Also includes stb_image header

To use a different graphical API, just edit the CMakeLists in `lib` to use a different ImGui backend

### SDL2

SDL2 is a bit messy to 'get' unless you use the provided submodule (and checkout a release version)

Currently the below method, using SDL2_DIR on **Windows** is not working correctly, so use the Git Submodule to grab SDL2, this should be done by default as long as the repository is cloned with --recursive, if not theres a lot of posts on how to init and clone submodules. Just remember that if you need a specific commit (you probably will for SDL2 as it defaults to cloning the `main` branch (SDL3) so make sure to grab a release that you want.)

If you enable the USE_SDL_SYS CMake Variable, it will use system SDL2 libs (on Linux devices) or use the directory specified by 'SDL2_DIR' (see Sample Commands for CMake syntax :D )

On Windows, it is recommended to use the 'devel' libs, in a local folder as the source for your SDL2 libraries, for release its a little different, at some point I will set up automatic downloading of development/release libraries and scripts to automatically wrap up release versions with their dlls, but I've not done that before so I'll have to experiment a bit

### Sample commands
Use something like this for a Ninja build project on **Windows/MSVC**

Specifying an SDL dir is not needed if using the Git Submodule method to getting SDL


```cmd
cmake ../ -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DSDL2_DIR=C:\SDL2\cmake
```

In case you add more SDL2 libraries, use these variables to specify their locations:

```cmd
-DSDL2_mixer_DIR=C:\SDL2_Mixer\cmake -DSDL2_image_DIR=C:\SDL2_Image\cmake -DSDL2_ttf_DIR=C:\SDL2_TTF\cmake
```

On **Linux**, it should be as simple as specifying your project file to be generated (Ninja, Make, etc) and hitting go as long as you have the SDL2 libs installed that you need