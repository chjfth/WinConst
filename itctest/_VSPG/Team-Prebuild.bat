@REM This sample applies to all of 
@REM Team-Prebuild.bat, Team-Postbuild.bat, Personal-Prebuild.bat, Personal-Postbuild.bat

@echo off
setlocal EnableDelayedExpansion

set batfilenam=%~n0%~x0
set batdir=%~dp0
set batdir=%batdir:~0,-1%
set _vspgINDENTS=%_vspgINDENTS%.
call :Echos START from "%batdir%"

REM == debugging purpose ==
REM call :EchoVar SolutionDir
REM call :EchoVar ProjectDir
REM call :EchoVar BuildConf
REM call :EchoVar IntrmDir
REM call :EchoVar TargetDir
REM call :EchoVar PlatformName
REM call :EchoVar TargetName

REM ==== Prelude Above ====

if not defined dir_gtest (
	call :Echos [BUG] Bat-var dir_gtest is not defined, there is problem with VSPU-StartEnv.bat
	exit /b 4
)

set gtest_buildbazel=%dir_gtest%\BUILD.bazel

if not exist "%gtest_buildbazel%" (
	call :Echos [CHECK] File should exist: "%gtest_buildbazel%"
	call :Echos [ERROR] The GoogleTest Git submodule has not been fetched, I cannot continue.
	exit /b 4
)

set isokBuildConf=
if "%BuildConf%"=="Debug-vs2019" set isokBuildConf=1
if "%BuildConf%"=="Release" set isokBuildConf=1
if not defined isokBuildConf (
	call :Echos [ERROR] Please select "Debug-vs2019" or "Release" to be your BuildConf. Your current BuildConf is "%BuildConf%", which is not supported.
	exit /b 4
)


set gtest_dllpath=%gtest_bindir%\gtest_0.dll

if not exist "%gtest_dllpath%" (
	call :Echos [CHECK] File should exist: "%gtest_dllpath%"
	call :Echos [ERROR] Googletest DLL should have been built using Bazel.
	exit /b 4
)


exit /b 0



REM =============================
REM ====== Functions Below ======
REM =============================

:Echos
  REM This function preserves %ERRORLEVEL% for the caller,
  REM and, LastError does NOT pollute the caller.
  setlocal & set LastError=%ERRORLEVEL%
  echo %_vspgINDENTS%[%batfilenam%] %*
exit /b %LastError%

:EchoAndExec
  echo %_vspgINDENTS%[%batfilenam%] EXEC: %*
  %*
exit /b %ERRORLEVEL%

:EchoVar
  setlocal & set Varname=%~1
  call echo %_vspgINDENTS%[%batfilenam%] %Varname% = %%%Varname%%%
exit /b 0

:SetErrorlevel
  REM Usage example:
  REM call :SetErrorlevel 4
exit /b %1

