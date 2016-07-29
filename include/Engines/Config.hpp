/*!
* \brief Define all the properties of the different engines
* \file Config.hpp
* \author Aredhele
* \version 0.1
* \date 2016-07-29
*/

#ifndef DEF_CONFIG_HPP
#define DEF_CONFIG_HPP

    // Global settings
    #define ENGINE_VERSION_MAJOR 0
    #define ENGINE_VERSION_MINOR 1
    #define ENGINE_VERSION_PATCH 0

    // Definition of DLL call type
    #define CDECL_DLL __cdecl
    #define STDCALL_DLL __stdcall
    #define FASTCALL_DLL __fastcall

    // Definition of dll symbols depending of the plateforme
    #if (defined(_WIN32) || defined(_WIN64))
        #define EXPORT_DLL __declspec(dllexport)
        #define IMPORT_DLL __declspec(dllimport)
    #elif defined(__linux__)
        #define EXPORT_DLL
        #define IMPORT_DLL
    #endif // Plateform symbols

    // Getting the library type
    // Static or Shared
    #if defined(ENGINE_SHARED)
        #define GRAPHIC_ENGINE_IMPORT IMPORT_DLL
        #define PHYSIC_ENGINE_IMPORT  IMPORT_DLL

        #define GRAPHIC_ENGINE_EXPORT EXPORT_DLL
        #define PHYSIC_ENGINE_EXPORT  EXPORT_DLL
    #else
        #define GRAPHIC_ENGINE_IMPORT
        #define PHYSIC_ENGINE_IMPORT

        #define GRAPHIC_ENGINE_EXPORT
        #define PHYSIC_ENGINE_EXPORT
    #endif // Library type

    // Checking the DLL symbols case
    // Compiling EXPORT
    // Running IMPORT
    #if defined(BUILD_ENGINE)
        #define GRAPHIC_API GRAPHIC_ENGINE_EXPORT
        #define PHYSIC_API  PHYSIC_ENGINE_EXPORT
    #else
        #define GRAPHIC_API GRAPHIC_ENGINE_IMPORT
        #define PHYSIC_API  PHYSIC_ENGINE_IMPORT
    #endif // DLL Symbols case

#endif // DEF_CONFIG_HPP





