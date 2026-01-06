@echo off
echo ========================================
echo   COMPILATION ET TEST DU PROJET
echo ========================================
echo.

echo [1] Test ultime...
gcc -o test_ultime.exe test_ultime.c
if errorlevel 1 goto compile_error
test_ultime.exe
if errorlevel 1 goto test_error
echo  Test ultime réussi
echo.

echo [2] Compilation des tests complets...
gcc -o tests.exe src/longest_substring.c tests/test_longest_substring.c
if errorlevel 1 goto compile_error
echo  Compilation réussie
echo.

echo [3] Execution des 15 tests...
echo.
tests.exe
if errorlevel 1 goto test_error
echo.

echo [4] Nettoyage...
del test_ultime.exe tests.exe 2>nul
echo.

echo ========================================
echo    SUCCES TOTAL!
echo ========================================
echo Tous les tests sont passés.
echo L'algorithme fonctionne correctement.
echo.
pause
exit 0

:compile_error
echo.
echo  ERREUR: Impossible de compiler
echo.
pause
exit 1

:test_error
echo.
echo  ERREUR: Tests échoués
echo.
pause
exit 1