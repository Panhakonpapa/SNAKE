#!bin/bash

COMPILER="gcc" 
LINKER="-lSDL2"
OUTFILE="out"
STDIN="main.c"
LINKING="game_libs/"
$COMPILER $STDIN -o $OUTFILE $LINKING $LINKER    

