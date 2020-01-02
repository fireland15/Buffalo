workspace "Meatball"
    startproject "Playground"
    architecture "x86_64"
    location "Build"
    configurations { "Debug", "Release" }
    filter { "configurations:Debug" }
        symbols "On"
        defines { "MEATBALL_DEBUG", "MEATBALL_PROFILE" }
    filter { "configurations:Release" }
        optimize "On"
    filter { }

    targetdir ("Bin/%{prj.name}/%{cfg.longname}")
    objdir ("Bin/Obj/%{prj.name}/%{cfg.longname}")

project "Meatball"
    kind "StaticLib"
    cppdialect "C++17"
    includedirs "%{prj.name}/Source"
    files { 
        "%{prj.name}/Source/**.hpp", 
        "%{prj.name}/Source/**.cpp"
    }
    warnings "Extra"
    defines { "_CRT_SECURE_NO_WARNINGS" }

function useMeatball()
    includedirs "Meatball/Source"
    links "Meatball"
end

project "Playground"
    kind "ConsoleApp"
    includedirs "%{prj.name}/Source"
    files {
        "%{prj.name}/Source/**.hpp",
        "%{prj.name}/Source/**.cpp"
    }
    useMeatball()