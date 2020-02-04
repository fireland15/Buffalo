$buildPath = "..\..\Build\Dependency\spdlog"
$spdlogPath = "..\..\Buffalo\Dependency\spdlog"
$outDir = "..\..\Lib\spdlog\"

$absBuildPath = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($buildPath);
$absSpdlogPath = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($spdlogPath);
$absOutDir = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($outDir);

Write-Host "Build Path: $absBuildPath"
Write-Host "Spdlog Path: $absSpdlogPath"
Write-Host "Output Dir: $absOutDir"

function GenerateSpdlogProjects() {
    Write-Host "Generating Spdlog build projects via cmake."
    
    if (Test-Path $absBuildPath) {
        Write-Host "Removing existing Spdlog project files."
        Remove-Item $absBuildPath -Recurse
    }

    Write-Host "Creating new directory for Spdlog build projects."
    New-Item -Path $absBuildPath -ItemType "directory" | Out-Null

    Push-Location -Path $absBuildPath

    cmake $absSpdlogPath -G "Visual Studio 16 2019" -A x64 

    Pop-Location
}

function BuildSpdlog() {
    $projectFilePath = Join-Path -Path $absBuildPath -ChildPath "spdlog.vcxproj"
    Write-Host "Building Spdlog with msbuild"
    Write-Host $projectFilePath
    msbuild $projectFilePath /p:OutDir=$absOutDir /p:Configuration=Release /verbosity:minimal
}

GenerateSpdlogProjects
BuildSpdlog