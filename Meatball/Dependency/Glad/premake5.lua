workspace "glad"
    architecture "x86_64"
    location "../../../Build/Dependency/Glad"
    configurations { "Debug", "Release" }
    filter { "configurations:Debug" }
        symbols "On"
    filter { "configurations:Release" }
        optimize "On"
    filter { }

    targetdir ("../../../Lib/%{prj.name}/%{cfg.longname}")
    objdir ("../../../Bin/Obj/%{prj.name}/%{cfg.longname}")

project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir "../../../Lib"
    objdir "../../../Build/Dependency/Glad"

    files {
        "include/glad/glad.h",
        "include/glad/khrplatform.h",
        "src/glad.c"
    }

    includedirs {
        "glad"
    }