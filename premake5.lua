workspace "Buffalo"
    startproject "Playground"
    architecture "x86_64"
    location "Build"
    configurations { "Debug", "Release" }
    filter { "configurations:Debug" }
        symbols "On"
        defines { "BUFFALO_DEBUG", "BUFFALO_PROFILE", "BUFFALO_LOG_LEVEL_TRACE" }
    filter { "configurations:Release" }
        optimize "On"
    filter { }

    targetdir ("Bin/%{prj.name}/%{cfg.longname}")
    objdir ("Bin/Obj/%{prj.name}/%{cfg.longname}")

project "Buffalo"
    kind "StaticLib"
    cppdialect "C++17"
    includedirs {
        "%{prj.name}/Source",
        "%{prj.name}/Dependency/Glfw/include",
        "%{prj.name}/Dependency/spdlog/include",
        "%{prj.name}/Dependency/Glad",
        "%{prj.name}/Dependency/glm"
    }
    files { 
        "%{prj.name}/Source/**.hpp", 
        "%{prj.name}/Source/**.cpp"
    }
    links {
        "Lib/Glfw/glfw3.lib",
        "Lib/Glad/glad.lib"
    }
    warnings "Extra"
    defines { "_CRT_SECURE_NO_WARNINGS" }

function useBuffalo()
    includedirs {
        "Buffalo/Source",
        "Buffalo/Dependency/spdlog/include",
        "Buffalo/Dependency/glm",
        "Buffalo/Dependency/glad"
    }
    links "Buffalo"
end

project "Playground"
    kind "ConsoleApp"
    cppdialect "C++17"
    includedirs {
        "%{prj.name}/Source"
    }
    files {
        "%{prj.name}/Source/**.hpp",
        "%{prj.name}/Source/**.cpp"
    }
    useBuffalo()