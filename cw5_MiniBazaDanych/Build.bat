@cls
@SET PATH+="D:\etools\IDE\x86\mingw\GCC4.4.0\bin"
@if not exist "obj\" mkdir obj\

@echo **************************** [COMPILING] ****************************
@mingw32-make.exe

@if %ERRORLEVEL% neq 0 ( @goto FAILED )
@goto SUCCESS

:FAILED
@echo ************************ [COMPILING FAILED] *************************
@pause
@exit /B 1

:SUCCESS
@echo *********************** [COMPILATION SUCCESS] ************************

@echo *************************** [PROGRAM RUN] ****************************
main.exe
@pause