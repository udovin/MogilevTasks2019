#!/bin/bash

function runPretestGen {

tcat <<<"\
9
info 1 5
info 1 7
rollback 1
check 1
clone 1
undo 2
check 2
rollback 1
check 1"

}

function runTestGen {

# Subtask 1 (5 tests): n <= 1000, no undo
tgen ../gen n='[10;20]' undo_c=0
tgen ../gen n='[300;500]' undo_c=0
tgen ../gen n=1000 undo_c=0
tgen ../gen n=1000 undo_c=0 ruZones=1
tgen ../gen n=1000 undo_c=0 clone_gc=0.33

# Subtask 2 (10 tests): n <= 1000
tgen ../gen n='[10;20]'
tgen ../gen n='[300;500]'
tgen ../gen n=1000
tgen ../gen n='[900;1000]' rollback_c=2 ruZones=1
tgen ../gen n='[900;1000]' ruZones=5

tgen ../gen n='[900;1000]' ruZones=1 rollback_c=0.2 undo_c=3
tgen ../gen n='[900;1000]' ruZones=2 info_c=10 check_gc=0.4 clone_gc=0.1
tgen ../gen n='[900;1000]' ruZones=2 undo_c=2 clone_gc=0.4
tgen ../gen n='[900;1000]'
tgen ../gen n='[900;1000]' ruZones=1 rollback_c=0.5 undo_c=0.5

# Subtask 3 (5 tests): no clone and undo
tgen ../gen n='[9900;10000]' clone_gc=0.0 undo_c=0
tgen ../gen n='[99000;100000]' clone_gc=0.0 undo_c=0
tgen ../gen n=500000 clone_gc=0.0 undo_c=0
tgen ../gen n=500000 clone_gc=0.0 undo_c=0 ruZones=1
tgen ../gen n='[499000;500000]' clone_gc=0.0 undo_c=0

# Subtask 4 (5 tests): no clone 
tgen ../gen n='[9900;10000]' clone_gc=0.0
tgen ../gen n='[99000;100000]' clone_gc=0.0
tgen ../gen n='[499000;500000]' clone_gc=0.0
tgen ../gen n=500000 clone_gc=0.0 ruZones=2
tgen ../gen n=500000 clone_gc=0.0 ruZones=1 rollback_c=0.5 undo_c=0.5

# Subtask 5 (10 tests): no undo
tgen ../gen n='[49000;50000]' undo_c=0 
tgen ../gen n='[299000;300000]' undo_c=0 ruZones=1
tgen ../gen n=500000 undo_c=0 clone_gc=0.5
tgen ../gen n=500000 undo_c=0 rollback_c=0.001 ruZones=4
tgen ../gen n='[499000;500000]' undo_c=0 clone_gc=0.4 rollback_c=0.2

tmany 5 ../gen n='[499000;500000]' undo_c=0

# Subtask 6 (15 tests): n <= 500000
tgen ../gen n='[80000;160000]'
tgen ../gen n=500000
tgen ../gen n='[495000;500000]' ruZones=1
tgen ../gen n='[495000;500000]' ruZones=1 clone_gc=0.6 check_gc=0.1
tgen ../gen n='[495000;500000]' ruZones=1 ruLens=200000 info_c=100

tgen ../gen n='[495000;500000]' ruZones=1 rollback_z=0 undo_c=0 undo_z=1
tgen ../gen n='[495000;500000]' ruZones=1 rollback_c=1 rollback_z=0.1 undo_c=0.1 undo_z=1 clone_gc=0.5
tmany 3 ../gen n='[495000;500000]' ruZones=2 rollback_c=1 rollback_z=0.2 undo_c=0.2 undo_z=1 clone_gc=0.2

tmany 3 ../gen n='[495000;500000]' ruZones=10 rollback_c=1 rollback_z=0.1 undo_c=0.1 undo_z=0.5 clone_gc=0.3
tmany 2 ../gen n='[495000;500000]' ruZones=2

}
