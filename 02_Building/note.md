|          | Windows     | Unix             |
| -------- | ----------- | ---------------- |
| RUNTIME  | .exe, .dll  | executable file  |
| LIBRARY  |             | .so              |
| ARCHIVE  | .a, .lib for .dll  | .a        |


```set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)```

```set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)```

```set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)```


|          | Windows  | Unix    |
| -------- | -------- |-------- |
| STATIC   |  .lib    | .a      |
| SHARED  |     | .so    |
| DYNAMIC  |  .dll    | .so   |

https://www.ptt.cc/man/C_and_CPP/DBF2/D139/DA10/M.1212250886.A.DF4.html

http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html

There are two Linux C/C++ library types which can be created:

* Static libraries (.a): Library of object code which is linked with, and becomes part of the application.
Dynamically linked shared object libraries (.so): There is only one form of this library but it can be used in two ways.
* Dynamically linked at run time. The libraries must be available during compile/link phase. The shared objects are not included into the executable component but are tied to the execution.
* Dynamically loaded/unloaded and linked during execution (i.e. browser plug-in) using the dynamic linking loader system functions.
