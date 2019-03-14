#!/bin/bash

function runPretestGen {

tcat <<<"\
4
4 1 1 5"

}


function runTestGen {

tzip ../fib_tests.zip fib1{a..f}.in  # 6 tests
tzip ../fib_tests.zip fib2{a..f}.in  # 6 tests
tzip ../fib_tests.zip fib3{a..b}.in  # 2 tests
tzip ../fib_tests.zip fib4{a..i}.in  # 9 tests
tzip ../fib_tests.zip fib5{a..c}.in  # 3 tests
tzip ../fib_tests.zip fib6{a,c,e,g,i,j,k,l,o,p}.in  # 10 tests
tzip ../fib_tests.zip fib7{{b..i},{k..p}}.in  # 14 tests

}
