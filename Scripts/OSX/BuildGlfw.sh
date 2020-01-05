#!/bin/bash
buildPath=../../Build/Dependency/Glfw
glfwPath=../../Meatball/Dependency/GLfw
outDir=../../Lib/Glfw

echo Build Path: $buildPath
echo GLFW Path: $glfwPath
echo Output Dir: $outDir

function GenerateGlfwProjects() {
    echo Generating GLFW build projects via cmake. 

    if [ -d $buildPath ]
    then
        echo Removing existing Glfw project files.
        rm -r $buildPath
    fi

    echo Creating new directory for Glfw build projects.
    cd ../../Build

    if [ ! -d Dependency ]
    then
        mkdir Dependency
    fi
    cd Dependency

    if [ ! -d Glfw ]
    then
        mkdir Glfw
    fi
    cd Glfw 

    cmake ../../../Meatball/Dependency/Glfw -G "Unix Makefiles" -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF
}

function BuildGlfw() {
    echo Building GLFW with Makefiles
    make   
    
    cd ../../../
    if [ ! -d Lib ]
    then
        mkdir Lib
    fi

    mv Build/Dependency/Glfw/src/libglfw3.a ./Lib
}

GenerateGlfwProjects
BuildGlfw