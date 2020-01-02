project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir (WHAT GOES HERE?)
    objdir (WHAT GOES HERE?)

    files {
        "include/glad.h",
        "include/khrplatform.h",
        "src/glad.c"
    }

    includedirs {
        "include"
    }