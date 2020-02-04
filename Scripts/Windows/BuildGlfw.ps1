$buildPath = "..\..\Build\Dependency\Glfw"
$glfwPath = "..\..\Buffalo\Dependency\Glfw"
$outDir = "..\..\Lib\Glfw\"

$absBuildPath = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($buildPath);
$absGlfwPath = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($glfwPath);
$absOutDir = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($outDir);

Write-Host "Build Path: $absBuildPath"
Write-Host "GLFW Path: $absGlfwPath"
Write-Host "Output Dir: $absOutDir"

function GenerateGlfwProjects() {
    Write-Host "Generating GLFW build projects via cmake."
    
    if (Test-Path $absBuildPath) {
        Write-Host "Removing existing Glfw project files."
        Remove-Item $absBuildPath -Recurse
    }

    Write-Host "Creating new directory for Glfw build projects."
    New-Item -Path $absBuildPath -ItemType "directory"

    Push-Location -Path $absBuildPath

    cmake $absGlfwPath -G "Visual Studio 16 2019" -A x64 -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF

    Pop-Location
}

function BuildGlfw() {
    $projectFilePath = Join-Path -Path $absBuildPath -ChildPath "GLFW.sln"
    Write-Host "Building GLFW with msbuild"
    Write-Host $projectFilePath
    msbuild $projectFilePath /p:OutDir=$absOutDir /p:Configuration=Release /verbosity:minimal
}

GenerateGlfwProjects
BuildGlfw