CMake variable has a concept of scope like variables in other programming languages.

(1)add_subdirectory, (2)include, (3)function and (4)macro show different behaviors in terms of the variable scope.

In summary, add_subdirectory and function both **create a new scope and copies**, but include and macro s**hare the scope with the parent (where they are called)**.

* Reference

[CMake Variable Scope](https://levelup.gitconnected.com/cmake-variable-scope-f062833581b7)