#!/bin/bash

function runPretestGen {

tcat <<<"\
3
1 1 1
3
1 1
2 1
3 1"

}


function runTestGen {

# Subtask 1: n, q <= 1000
tmany 5 ../gen_random n=1000 q=1000
tgen ../gen_random n='[900;1000]' q='[900;1000]'
tgen ../gen_random n=1000 q=1000 apol=0 kpol=0
tgen ../gen_random n=1000 q=1000 apol=-10 kpol=-10

# Subtask 2: a_i = 1
tgen ../gen_random n=200000 q=200000 amax=1
tgen ../gen_random n=200000 q=200000 amax=1 kpol=0
tgen ../gen_random n=200000 q=200000 amax=1 kpol=-15
tgen ../gen_sqrt n=200000 q=200000 amax=1 sqrng=600
tgen ../gen_sqrt n='[190000;200000]' q='[190000;200000]' amax=1 sqrng=400
tgen ../gen_sqrt n='[190000;200000]' q='[190000;200000]' amax=1 sqrng=100
tgen ../gen_random n='[190000;200000]' q=200000 amax=1 kpol=-40000 ppol=-40000
tgen ../gen_random n='[190000;200000]' q=200000 amax=1 kpol=-100000 ppol=-100000
tgen ../gen_random n='[190000;200000]' q=200000 kmin=3 amax=1 kpol=-100000 ppol=-100000
tgen ../gen_random n='[190000;200000]' q=200000 kmin=3 amax=1 kpol=-300000 ppol=-300000

# Subtask 3: n <= 6000
tgen ../gen_random n=6000 q=200000
tgen ../gen_random n='[5900;6000]' q='[199000;200000]' kpol=0 apol=0
tgen ../gen_random n='[5900;6000]' q='[199000;200000]' kpol=-15 apol=-15
tgen ../gen_sqrt n='[5900;6000]' q='[199000;200000]' apol=-15 sqrng=100
tgen ../gen_sqrt n='[5900;6000]' q='[199000;200000]' apol=0 sqrng=100
tgen ../gen_sqrt n='[5900;6000]' q='[199000;200000]' sqrng=50
tgen ../gen_sqrt n='[5900;6000]' q='[199000;200000]' sqrng=100
tgen ../gen_sqrt n='[5900;6000]' q='[199000;200000]' amax=4 sqrng=100
tgen ../gen_random n=6000 q=200000 amax=4
tgen ../gen_random n='[5900;6000]' q=200000 amax=1 kpol=-40000 ppol=-40000
tgen ../gen_random n='[5900;6000]' q=200000 amax=2 kpol=-100000 ppol=-100000
tgen ../gen_random n='[5900;6000]' q=200000 kmin=3 amax=1 kpol=-100000 ppol=-100000
tgen ../gen_random n='[5900;6000]' q=200000 kmin=3 amax=2 kpol=-300000 ppol=-300000

# Subtask 4: n, q <= 200000
tgen ../gen_random n=200000 q=200000
tgen ../gen_random n=200000 q=200000 apol=-6 kpol=-3
for sqrng in 0 600; do
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' apol=0 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' apol=-1 kpol=-1 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' apol=-1 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' apol=-15 kpol=-15 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' apol=-15 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' apol=-1000 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' apol=-100000 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' amax=3 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' amax=3 apol=-3 sqrng=$sqrng
	tgen ../gen_sqrt n='[195000;200000]' q='[195000;200000]' amax=1 sqrng=$sqrng
done
tgen ../gen_random n=200000 q=200000 amax=1 kpol=-40000 ppol=-40000
tgen ../gen_random n=200000 q=200000 amax=2 kpol=-100000 ppol=-100000
tgen ../gen_random n=200000 q=200000 kmin=3 amax=1 kpol=-100000 ppol=-100000
tgen ../gen_random n=200000 q=200000 kmin=3 amax=2 kpol=-300000 ppol=-300000


}
