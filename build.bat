@echo off
echo ========================================
echo   PROJET C - COMPILATION ET TESTS
echo ========================================
echo.

echo [1] Compilation des tests...
gcc -Wall -std=c99 -o tests.exe src/longest_substring.c tests/test_longest_substring.c
if errorlevel 1 goto compile_error

echo [2] Execution des tests...
echo.
tests.exe
if errorlevel 1 goto test_error

echo [3] Nettoyage...
del tests.exe 2>nul

echo.
echo ========================================
echo         SUCCES TOTAL!
echo ========================================
echo  Tous les tests passent
echo  Algorithme fonctionnel (O(n))
echo  Projet pret pour soumission
echo.
echo Appuyez sur une touche pour quitter...
pause > nul
exit 0

:compile_error
echo.
echo  ERREUR: Compilation echouee
echo.
pause
exit 1

:test_error
echo.
echo  ERREUR: Tests echoues
echo.
pause
exit 1