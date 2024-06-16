gcc memoizationChange.c -o memoizationChange.exe
gcc bottomUpChange.c -o bottomUpChange.exe

./memoizationChange.exe
./bottomUpChange.exe

rm -rf *.exe