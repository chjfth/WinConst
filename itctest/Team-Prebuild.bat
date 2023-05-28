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

REM Get WinConst repository full dirpath into REPO.
call :GetAbsPath REPO ..

set gtest_buildbazel=%REPO%\__googletest\BUILD.bazel

if not exist "%gtest_buildbazel%" (
	call :Echos [CHECK] File should exist: "%gtest_buildbazel%"
	call :Echos [ERROR] The GoogleTest Git submodule has not been fetched, I cannot continue.
	exit /b 4
)

if not "%BuildConf%"=="Debug-vs2019" (
	call :Echos [ERROR] Please select "Debug-vs2019" to be your BuildConf. Your current BuildConf is "%BuildConf%", which is not supported.
	exit /b 4
)

if "%PlatformName%"=="Win32" (
	set gtest_bcxdir=x64_x86_windows-dbg
) else if "%PlatformName%"=="x64" (
	set gtest_bcxdir=x64_windows-dbg
) else if "%PlatformName%"=="ARM64" (
	set gtest_bcxdir=arm64_windows-dbg
)

set gtest_bazeloutdir=%REPO%\__googletest\bazel-out
set gtest_bindir=%gtest_bazeloutdir%\%gtest_bcxdir%\bin

set gtest_dllpath=%gtest_bindir%\gtest_0.dll

if not exist "%gtest_dllpath%" (
	call :Echos [CHECK] File should exist: "%gtest_dllpath%"
	call :Echos [ERROR] To continue, Googletest DLL should have been built using Bazel.
	
	if not exist "%gtest_bindir%\_obj" (
		call :Echos [INFO] Now removing directory "%gtest_bazeloutdir%" because I think it is NOT generated by Bazel.
		call :EchoAndExec rmdir /s /q "%gtest_bazeloutdir%"
	)
	
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

:GetAbsPath
  REM Get absolute-path from a relative-path. If already absolute, return as is.
  REM Param1: Var name to receive output.
  REM Param2: The input path.
  if "%~1"=="" exit /b 4
  if "%~2"=="" exit /b 4
  for %%a in ("%~2") do set "%~1=%%~fa"
exit /b 0