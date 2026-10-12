param(
    [ValidateSet("configure", "build", "test", "run")]
    [string]$Action = "build"
)

$ErrorActionPreference = "Stop"
$repoRoot = Split-Path -Parent $PSScriptRoot
$buildDir = Join-Path $repoRoot "out\build\x64-Debug"

$vsDevCmd = @(
    "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat",
    "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\Tools\VsDevCmd.bat",
    "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\VsDevCmd.bat",
    "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"
) | Where-Object { Test-Path $_ } | Select-Object -First 1

if (-not $vsDevCmd) {
    throw "Visual Studio Developer Command Prompt를 찾을 수 없습니다. Visual Studio C++ 데스크톱 개발 도구를 설치하세요."
}

function Invoke-CMakeInVsEnvironment([string]$command) {
    $cmdLine = 'call "{0}" -arch=x64 && {1}' -f $vsDevCmd, $command
    & cmd.exe /d /s /c $cmdLine
    if ($LASTEXITCODE -ne 0) {
        throw "명령 실행 실패($LASTEXITCODE): $command"
    }
}

switch ($Action) {
    "configure" {
        Invoke-CMakeInVsEnvironment ('cmake -S "{0}" -B "{1}" -G Ninja -DCMAKE_BUILD_TYPE=Debug' -f $repoRoot, $buildDir)
    }
    "build" {
        Invoke-CMakeInVsEnvironment ('cmake --build "{0}" --config Debug' -f $buildDir)
    }
    "test" {
        Invoke-CMakeInVsEnvironment ('ctest --test-dir "{0}" -C Debug --output-on-failure' -f $buildDir)
    }
    "run" {
        $app = Join-Path $buildDir "BattleApp.exe"
        if (-not (Test-Path $app)) {
            throw "BattleApp.exe가 없습니다. 먼저 CMake: Build Debug를 실행하세요."
        }
        & $app
        if ($LASTEXITCODE -ne 0) {
            throw "BattleApp 실행 실패($LASTEXITCODE)"
        }
    }
}
