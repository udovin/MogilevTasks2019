#!/bin/bash

function runPretestGen {

tcat <<<"\
3
1 2 3"

tcat <<<"\
4
1 2 1 2"

tcat <<<"\
12
1 2 3 1 2 3 1 2 3 1 2 3"

tcat <<<"\
12
1 2 3 1 2 3 1 2 3 1 2 3"

tcat <<<"\
1
1"

}


function runTestGen {

# Subtask 1 (5 tests): n <= 9
group 1
tgen ../gen n=1 cnt=1
tgen ../gen n=9 cnt=2
tgen ../gen n=9 cnt=3
tgen ../gen n=9 cnt=4
tgen ../gen n=9 cnt=9 polar=6

# Subtask 2 (5 tests): a[i] <= 2
group 2
tgen ../gen n=20 psz=2 cnt=2
tgen ../gen n=100 psz=2 cnt=2
tgen ../gen n=300 psz=2 cnt=2
tgen ../gen n=400 psz=2 cnt=2
tgen ../gen n=500 psz=2 cnt=2

# Subtask 3 (10 tests): n <= 20
group 3
tgen ../gen n=15 cnt=15 polar=6
tgen ../gen n=20 cnt=5
tgen ../gen n=20 cnt=3
tgen ../gen n=20 cnt=3 polar=1
tgen ../gen n=20 cnt=20 polar=3

tgen ../gen n=20 cnt=20 polar=1
tgen ../gen n=20 cnt=15
tgen ../gen n=20 cnt=13
tgen ../gen n=20 cnt=10
tgen ../gen n=20 cnt=9 polar=1

# Subtask 4 (15 tests): n <= 100
group 4
tgen ../gen n=55  cnt=55 polar=10
tgen ../gen n=100 cnt=100
tgen ../gen n=100 cnt=100 polar=2
tgen ../gen n=100 cnt=80
tgen ../gen n=100 cnt=60

tgen ../gen n=100 cnt=100 polar=10
tgen ../gen n=100 cnt=50 polar=6
tgen ../gen n=100 cnt=50 polar=4
tgen ../gen n=100 cnt=100 polar=1
tgen ../gen n=100 cnt=100 polar=3

tgen ../gen n=100 cnt=3
tgen ../gen n=100 cnt=3 polar=3
tgen ../gen n=100 cnt=4
tgen ../gen n=100 cnt=5
tgen ../gen n=100 cnt=7

# Subtask 5 (15 tests): n <= 500
group 5
tgen ../gen n=200 cnt=200 polar=10
tgen ../gen n=300 cnt=300
tgen ../gen n=500 cnt=350
tgen ../gen n=500 cnt=250
tgen ../gen n=500 cnt=500

tgen ../gen n=500 cnt=500 polar=40
tgen ../gen n=500 cnt=500 polar=10
tgen ../gen n=500 cnt=300 polar=3
tgen ../gen n=500 cnt=200 polar=2
tgen ../gen n=500 cnt=500 polar=6

tgen ../gen n=500 cnt=3
tgen ../gen n=500 cnt=3 polar=3
tgen ../gen n=500 cnt=10
tgen ../gen n=500 cnt=500 polar=2
tgen ../gen n=500 cnt=500 polar=4

}
