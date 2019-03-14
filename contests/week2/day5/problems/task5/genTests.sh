#!/bin/bash

function runPretestGen {

tcat <<<"\
0
3 5 1 6
FFFFF
FCCCF
FFFFF"

}


function runTestGen {

tgen ../gen-boxes t=1 n=9 m=10 l=2 h=7
tgen ../gen-boxes t=2 n=20 m=20 l=5 h=21
tgen ../gen-random t=3 n=64 m=64 l=6 h=14 cu=0.5
tgen ../gen-random t=4 n=250 m=200 l=20 h=49 cu=0.6
tgen ../gen-boxes t=5 n=200 m=100 l=1 h=4

tgen ../gen-random t=6 n=600 m=600 l=10 h=34 cu=0.3
tgen ../gen-chess t=7 n=1000 m=996 l=10 h=20
tgen ../gen-boxes t=8 n=1000 m=1000 l=7 h=28
tgen ../gen-random t=9 n=3 m=1000 l=30 h=72 cu=0.5
tgen ../gen-random t=10 n=1000 m=1000 l=82 h=280 cu=0.3

}
