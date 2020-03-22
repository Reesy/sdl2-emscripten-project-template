# SFML_Example_Project

This is an example project which will allow you to pull down 



How to clone:

```
git clone --recurse-submodules https://github.com/Reesy/sfml_vscode_project_template
```

This project imports it's dependency on SFML via a git submodule in the external_resources folder.

How to build:

Cmake is required to build this project, aswell as ensuring a suitable C++ compiler

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

This project comes with a .vscode folder prebundled to make debugging easier, for this to work two plugins are necessary 

<dl>
    <dt> Recommended Plugins<dt>
    <dd style='color:green'>C/C++ Plugin </dd>
    <dd style='color:green'>CodeLLDB* </dd>
<dl>

\*CodeLLDB is only recommended for debugging on modern OSX versions

SFML can be found http://www.sfml-dev.org
