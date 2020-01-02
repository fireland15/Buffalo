$buildPath = "..\..\Build\Dependency\Glfw"
$glfwPath = "..\..\Meatball\Dependency\Glfw"

function GenerateGlfwProjects() {
    Write-Host "Generating GLFW build projects via cmake."
    
    if (Test-Path $buildPath) {
        Write-Host "Removing existing Glfw project files."
        Remove-Item $buildPath -Recurse
    }

    Write-Host "Creating new directory for Glfw build projects."
    New-Item -Path $buildPath -ItemType "directory"

    Push-Location -Path $glfwPath

    cmake $buildPath -G "Visual Studio 16 2019" -A x64

    Pop-Location
}

GenerateGlfwProjects