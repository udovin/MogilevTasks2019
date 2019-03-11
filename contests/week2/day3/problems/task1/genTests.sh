#!/bin/bash

function runPretestGen {

tcat <<<"\
9
0
0
0
2
0
0
3
1
0"

}


function runTestGen {

# Subtask 1 (10 tests) : n <= 3000
tgen ../gen n='[10;20]'     undo=0.5 
tgen ../gen n='[50;100]'    undo=0.5 
tgen ../gen n='[400;500]'   undo=0.5 
tgen ../gen n='[900;1000]'  undo=0.5 
tgen ../gen n='[2000;3000]' undo=0.5 

tgen ../gen n='[2800;3000]' undo=0.4 upolar=1
tgen ../gen n='[2800;3000]' undo=0.6
tgen ../gen n='[2800;3000]' undo=0.5
tgen ../gen n='[2800;3000]' undo=0.45 upolar=-1
tgen ../gen n='[2800;3000]' undo=0.1

# Subtask 1 (5 tests) : no remove queries
tgen ../gen n=200    undo=0
tgen ../gen n=2000   undo=0
tgen ../gen n=50000  undo=0
tgen ../gen n=88000  undo=0
tgen ../gen n=200000 undo=0

# Subtask 1 (35 tests) : n <= 200000

tgen ../gen n='[10000;20000]'   undo=0.5
tgen ../gen n='[45000;50000]'   undo=0.5
tgen ../gen n='[95000;100000]'  undo=0.5
tgen ../gen n='[180000;200000]' undo=0.5
tgen ../gen n=300000            undo=0.5

tgen ../gen n='[290000;300000]' undo=0.2 
tgen ../gen n='[290000;300000]' undo=0.2  upolar=1
tgen ../gen n='[290000;300000]' undo=0.25
tgen ../gen n='[290000;300000]' undo=0.25 upolar=1
tgen ../gen n='[290000;300000]' undo=0.25 upolar=-1

tgen ../gen n='[290000;300000]' undo=0.3
tgen ../gen n='[290000;300000]' undo=0.3  upolar=1
tgen ../gen n='[290000;300000]' undo=0.35
tgen ../gen n='[290000;300000]' undo=0.35 upolar=1
tgen ../gen n='[290000;300000]' undo=0.35 upolar=-1

tgen ../gen n='[290000;300000]' undo=0.4 
tgen ../gen n='[290000;300000]' undo=0.4 upolar=1
tgen ../gen n='[290000;300000]' undo=0.5
tgen ../gen n='[290000;300000]' undo=0.6 upolar=1
tgen ../gen n='[290000;300000]' undo=0.7 upolar=1

tgen ../gen n='[290000;300000]' undo=0.15 upolar=2
tgen ../gen n='[290000;300000]' undo=0.2  upolar=2
tgen ../gen n='[290000;300000]' undo=0.25 upolar=2
tgen ../gen n='[290000;300000]' undo=0.3  upolar=2
tgen ../gen n='[290000;300000]' undo=0.35 upolar=2

tgen ../gen n='[290000;300000]' undo=0.4  upolar=2
tgen ../gen n='[290000;300000]' undo=0.45 upolar=3
tgen ../gen n='[290000;300000]' undo=0.5  upolar=2
tgen ../gen n='[290000;300000]' undo=0.75 upolar=2
tgen ../gen n='[290000;300000]' undo=0.8  upolar=2

tgen ../gen n='[290000;300000]' undo=0.40 upolar=-2
tgen ../gen n='[290000;300000]' undo=0.41 upolar=-2
tgen ../gen n='[290000;300000]' undo=0.42 upolar=-2
tgen ../gen n='[290000;300000]' undo=0.43 upolar=-2
tgen ../gen n='[290000;300000]' undo=0.44 upolar=-2

}
