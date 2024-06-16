gcc backtrackingCutRod.c -o backtrackingCutRod.out
gcc topDownCutRod.c -o topDownCutRod.out
gcc bottomUpCutRod.c -o bottomUpCutRod.out

./backtrackingCutRod.out
./topDownCutRod.out
./bottomUpCutRod.out

rm -if *.out

