$buildPath = "..\..\Build\Dependency\Glad"
$gladPath = "..\..\Buffalo\Dependency\Glad"
$outDir = "..\..\Lib\Glad\"

$absBuildPath = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($buildPath);
$absgladPath = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($gladPath);
$absOutDir = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($outDir);

Write-Host "Build Path: $absBuildPath"
Write-Host "GLFW Path: $absgladPath"
Write-Host "Output Dir: $absOutDir"

function GenerateGladProjects() {
    Write-Host "Generating GLAD build projects via premake5."
    
    if (Test-Path $absBuildPath) {
        Write-Host "Removing existing GLAD project files."
        Remove-Item $absBuildPath -Recurse
    }

    Write-Host "Creating new directory for GLAD build projects."
    New-Item -Path $absBuildPath -ItemType "directory"

    Push-Location -Path $absGladPath

    premake5 vs2019

    Pop-Location
}

function BuildGlad() {
    $projectFilePath = Join-Path -Path $absBuildPath -ChildPath "GLAD.sln"
    Write-Host "Building GLFW with msbuild"
    Write-Host $projectFilePath
    msbuild $projectFilePath /p:OutDir=$absOutDir /p:Configuration=Release /verbosity:minimal
}

GenerateGladProjects
BuildGlad