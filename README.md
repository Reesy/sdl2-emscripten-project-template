# SDL2_VSCODE_PROJECT_TEMPLATE

This is an example project which will let you create SDL2 projects quickly, it has a very simple CMake build system.



How to clone:

```
git clone https://github.com/Reesy/sdl2_vscode_project_template
```

This project has a dependency on SDL2 and SDL_image, when building natively these dependencies must be installed on the target machine and they can be discovered through the FindSDL cmake files. When building through emscripten the SDL and SDL2 ports are required (they should exist by default)

<dl>
    <dt> Requirements<dt>
    <dd style='color:red'> CMake -- required to build this project </dd>
<dl>

To build a release (on OSX):

```
cmake . -B build
make
```

To build for browser with Emscripten (requires emscripten installed and on the path): 

```
emcmake cmake . -B build 
```

To build with debug symbols (on OSX):
```
cmake -DCMAKE_BUILD_TYPE=Debug . -B build
make
```

<div style='color:red'> The 'resources' folder needs to exist in the same directory as the .exe file (on OSX it will be automatically bundled into the app</div>


This project comes with a .vscode folder prebundled to make debugging easier, for this to work two plugins are necessary 

<dl>
    <dt> Recommended Plugins<dt>
    <dd style='color:green'>C/C++ Plugin </dd>
    <dd style='color:green'>CodeLLDB* </dd>
<dl>

\*CodeLLDB is only recommended for debugging on modern OSX versions

SDL2 can be found https://www.libsdl.org/


Emscripten command (manually):
    ```emcc src/main.cpp -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -O3 -o index.js```

    running in small httpserver with Python 2: ```python -m SimpleHTTPServer 8080``` 



Credit for the code in main from: 
    1. http://main.lv/writeup/web_assembly_sdl_example.md#toc-1   
    2. https://www.willusher.io/sdl2%20tutorials/2013/08/27/lesson-5-clipping-sprite-sheets 
