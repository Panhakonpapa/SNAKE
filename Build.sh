#!bin/bash

COMPILER="gcc" 
LINKER="-lSDL2"
OUTFILE="out"
STDIN="main.c"
LINKING="game_libs/libs.c"
$COMPILER $STDIN -o $OUTFILE $LINKING $LINKER    

