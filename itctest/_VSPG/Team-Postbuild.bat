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

REM ..... Copy itctest.exe to the dir of gtest_0.dll .....

set ev_listfiles_ToCopy=%TargetFileNam%
set ev_listdirs_CopyTo=%gtest_bindir%

call "%bootsdir%\CopyFilePatternsToDirs.bat" "%ExeDllDir%" ev_listfiles_ToCopy ev_listdirs_CopyTo 

if not !errorlevel!==0 exit /b 4

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
