@ECHO OFF
SETLOCAL
ECHO "RINGO ENGINE"

REM Set project path
PUSHD..
SET PROJECTPATH=%cd%
POPD

REM Path confirmation message
:PROMPT
SET /P CONFIRMATION=Are you sure that you want to clean the solution in the path: %PROJECTPATH% (Y/[N])?
IF /I "%CONFIRMATION%" NEQ "Y" GOTO WRONGPROJECTPATH

REM Remove the project files
PUSHD..
ECHO "Removing visual studio files"
DEL /s *.sln
DEL /s *.vcxproj
ECHO "Cleaning intermediate files"
FOR /d /r . %%d in (Intermediates) do @if exist "%%d" ECHO "%%d" && RD /s/q "%%d"
ECHO "Cleaning binary files"
FOR /d /r . %%d in (Binaries) do @if exist "%%d" ECHO "%%d" && RD /s/q "%%d"
GOTO :END

REM Wrong project path message.
:WRONGPROJECTPATH
ECHO "Please, review this script location. It should be located in the Scripts directory inside the ringo folder."
ECHO "Example: F:/Ringo/Scripts"

:END
ENDLOCAL
PAUSE