@ECHO OFF
SETLOCAL
ECHO "RINGO ENGINE"

REM Generate the project files
ECHO "Generating ringo project files"
PUSHD %~dp0\..\
CALL Engine\Third-party\premake\premake5.exe vs2019
POPD

ENDLOCAL
PAUSE