#!/bin/bash

function runPretestGen {

tcat <<<"\
3 3
7 1 4"

tcat <<<"\
5 7
1 5 3 5 3"

tcat <<<"\
9 15
6 7 4 1 1 5 2 5 2"

}


function runTestGen {

# Subtask 1 (2 tests): n <= 10000
group 1
tgen ../gen n=50
tgen ../gen n=10000

# Subtask 2 (6 tests): ai <= 5000
group 2
tgen ../gen n=100000 val='[1;5000]'
tgen ../gen n=500000 val='[1;10]'
tgen ../gen n=500000 val='[1;5000]' polar=10
tgen ../gen n='[490000;500000]' val='[1;5000]' k='[120000000000;120049755000]'
tgen ../gen n='[490000;500000]' val='[1;1]'
tgen ../gen n='[490000;500000]' val='[1;5000]' polar=1

# Subtask 3 (12 tests): k <= 1000000
group 3
tgen ../gen n=10000 k='[1;1000000]'
tgen ../gen n='[490000;500000]' k='[1;1000]'
tgen ../gen n='[490000;500000]' k='[1;1000000]' polar=1
tgen ../gen n='[490000;500000]' k='[1000000;1000000]' polar=100
tmany 4 ../gen n='[490000;500000]' k='[1;1000000]'
tmany 4 ../gen n='[490000;500000]' k='[1;1000000]' polar=500000000

# Subtask 4 (10 tests): n <= 100000
group 4
tgen ../gen n=100000
tgen ../gen n='[90000;100000]' polar=1
tgen ../gen n='[90000;100000]' val='[999999998;1000000000]'
tgen ../gen n='[90000;100000]' val='[999999900;1000000000]'
tgen ../gen n='[90000;100000]' polar=100000000
tgen ../gen n='[90000;100000]' k='[4000000000;4049955000]'
tmany 4 ../gen n='[90000;100000]'

# Subtask 5 (10 tests): n <= 500000
group 5
tgen ../gen n=500000
tgen ../gen n='[490000;500000]' polar=1
tgen ../gen n='[490000;500000]' val='[999999998;1000000000]'
tgen ../gen n='[490000;500000]' val='[999999900;1000000000]'
tgen ../gen n='[490000;500000]' polar=100000000
tgen ../gen n='[490000;500000]' k='[120000000000;120049755000]'
tmany 4 ../gen n='[490000;500000]'

}
