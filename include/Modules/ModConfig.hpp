/*!
* \brief Define all the properties of the different modules
* \file ModConfig.hpp
* \author Aredhele
* \version 0.1
* \date 2016-07-29
*/

#ifndef DEF_MOD_CONFIG_HPP
#define DEF_MOD_CONFIG_HPP

    // Global settings
    #define BUILD_DATE __DATE__
    #define MODULE_VERSION_MAJOR 0
    #define MODULE_VERSION_MINOR 1
    #define MODULE_VERSION_PATCH 0

    // Getting the version of the compiler
    #if (defined(__MINGW32__) || defined(__MINGW64))
        #define MINGW "MinGW"
        #define COMPILER MINGW
        #if defined(__GNUC__)
            #define COMPILER_MAJOR __GNUC__
            #define COMPILER_MINOR __GNUC_MINOR__
            #define COMPILER_PATCH __GNUC_PATCHLEVEL__
        #endif
    #elif defined(_MSC_VER)
        #define MVS "Microsoft Visual Studio"
        #pragma warning(disable: 4251)
        #define COMPILER MVS
    #else
        #define ERROR "Not Supported"
    #endif // Compiler

    // Getting the plateforme name
    #if (defined(_WIN32) || defined(_WIN64))
        #define WINDOWS
        #define PLATEFORME _WIN32
    #elif defined(__linux__)
        #define LINUX
        #define PLATEFORME __linux__
    #else
        #ifndef ERROR
            #define ERROR
        #endif // Error
    #endif // Plateforme

    // Definition of DLL call type
    #define CDECL_DLL __cdecl
    #define STDCALL_DLL __stdcall
    #define FASTCALL_DLL __fastcall

    // Definition of dll symbols depending of the plateforme
    #if defined(WINDOWS)
        #define EXPORT_DLL __declspec(dllexport)
        #define IMPORT_DLL __declspec(dllimport)
    #elif defined(LINUX)
        #define EXPORT_DLL
        #define IMPORT_DLL
    #endif // Plateform symbols

    // Getting the library type
    // Static or Shared
    #if defined(MOD_SHARED)
        #define INTERFACE_IMPORT IMPORT_DLL
        #define UTILITIES_IMPORT IMPORT_DLL

        #define INTERFACE_EXPORT EXPORT_DLL
        #define UTILITIES_EXPORT EXPORT_DLL
    #else
        #define INTERFACE_IMPORT
        #define UTILITIES_IMPORT

        #define INTERFACE_EXPORT
        #define UTILITIES_EXPORT
    #endif // Library type

    // Checking the DLL symbols case
    // Compiling EXPORT
    // Running IMPORT
    #if defined(BUILD_MOD)
        #define INTERFACE_API INTERFACE_EXPORT
        #define UTILITIES_API UTILITIES_EXPORT
    #else
        #define INTERFACE_API INTERFACE_IMPORT
        #define UTILITIES_API UTILITIES_IMPORT
    #endif // DLL Symbols case

#endif // DEF_MOD_CONFIG_HPP




