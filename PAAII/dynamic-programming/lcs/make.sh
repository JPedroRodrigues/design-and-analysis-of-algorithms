gcc bottomUpLcs.c -o bottomUpLcs.out
gcc backtrackingLcs.c -o backtrackingLcs.out
gcc topDownLcs.c -o topDownLcs.out

./bottomUpLcs.out
./backtrackingLcs.out
./topDownLcs.out

rm -if *.out
