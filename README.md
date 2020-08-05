# SFML_VSCODE_PROJECT_TEMPLATE

This is an example project which will let you create SFML projects quickly, it has a very simple CMake build system.



How to clone:

```
git clone --recurse-submodules https://github.com/Reesy/sfml_vscode_project_template
```

This project imports it's dependency on SFML via a git submodule in the external_resources folder.

<dl>
    <dt> Requirements<dt>
    <dd style='color:red'> CMake -- required to build this project </dd>
<dl>

To build a release (on OSX):

```
cmake .
make
```

To build with debug symbols (on OSX):
```
cmake -DCMAKE_BUILD_TYPE=Debug .
make
```

<div style='color:red'> 1. OpenAL is required to run the application </div>
<div style='color:red'> 2. The 'resources' folder needs to exist in the same directory as the .exe file (on OSX it will be automatically bundled into the app</div>


This project comes with a .vscode folder prebundled to make debugging easier, for this to work two plugins are necessary 

<dl>
    <dt> Recommended Plugins<dt>
    <dd style='color:green'>C/C++ Plugin </dd>
    <dd style='color:green'>CodeLLDB* </dd>
<dl>

\*CodeLLDB is only recommended for debugging on modern OSX versions

SFML can be found http://www.sfml-dev.org
