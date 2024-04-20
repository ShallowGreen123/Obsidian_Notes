-   `COMPONENT_DIR`: The component directory. Evaluates to the absolute path of the directory containing `CMakeLists.txt`. The component path cannot contain spaces. This is the same as the `CMAKE_CURRENT_SOURCE_DIR` variable.
    
-   `COMPONENT_NAME`: Name of the component. Same as the name of the component directory.
    
-   `COMPONENT_ALIAS`: Alias of the library created internally by the build system for the component.
    
-   `COMPONENT_LIB`: Name of the library created internally by the build system for the component.

-   `PROJECT_NAME`: Name of the project, as set in project CMakeLists.txt file.
    
-   `PROJECT_DIR`: Absolute path of the project directory containing the project CMakeLists. Same as the `CMAKE_SOURCE_DIR` variable.
    
-   `COMPONENTS`: Names of all components that are included in this build, formatted as a semicolon-delimited CMake list.
    
-   `IDF_VER`: Git version of ESP-IDF (produced by `git describe`)
    
-   `IDF_VERSION_MAJOR`, `IDF_VERSION_MINOR`, `IDF_VERSION_PATCH`: Components of ESP-IDF version, to be used in conditional expressions. Note that this information is less precise than that provided by `IDF_VER` variable. `v4.0-dev-*`, `v4.0-beta1`, `v4.0-rc1` and `v4.0` will all have the same values of `IDF_VERSION_*` variables, but different `IDF_VER` values.
    
-   `IDF_TARGET`: Name of the target for which the project is being built.
    
-   `PROJECT_VER`: Project version.