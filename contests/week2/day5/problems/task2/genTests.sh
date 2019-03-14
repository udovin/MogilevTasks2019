#!/bin/bash

function runPretestGen {

tcat <<<"\
2
2 1
3"

tcat <<<"\
1
1
1"

tcat <<<"\
4
5 2 1 3
15"

tcat <<<"\
2
5 3
2"

}


function runTestGen {

tgen ../gen 3 5 4 1 aa
tgen ../gen 1 1 1 1 ab
tgen ../gen 4 5 15 1 hc
tgen ../gen 2 5 2 0 gd
tgen ../gen 1 25 25 1 ce
tgen ../gen 1 25 25 0 af
tgen ../gen 1 25 25 1 hg
tgen ../gen 3 25 25 1 gh
tgen ../gen 3 25 25 1 gi
tgen ../gen 3 25 25 1 gj
tgen ../gen 3 12 25 1 gk
tgen ../gen 5 25 25 1 gq
tgen ../gen 5 25 25 1 gr
tgen ../gen 5 25 25 1 gs
tgen ../gen 5 25 25 1 gt
tgen ../gen 5 25 25 1 gu
tgen ../gen 50 64 100000 1 gl
tgen ../gen 231 100000 100000 1 gm
tgen ../gen 12344 100000 100000 1 gn
tgen ../gen 50000 100000 100000 1 go
tgen ../gen 70000 100000 100000 1 gp
tgen ../gen 100000 100000 100000 1 gv
tgen ../gen 100000 100000 100000 1 gw
tgen ../gen 100000 100000 100000 1 gx
tgen ../gen 100000 100000 100000 1 gy
tgen ../gen 100000 100000 100000 1 gz
tgen ../gen 100000 100000 100000 1 ha
tgen ../gen 100000 100000 100000 0 hb
tgen ../gen 3 4 100000 1 hc
tgen ../gen 1 1 100000 1 hd
tgen ../gen 100 1200 1000000000000 1 he
tgen ../gen 500 4444 1000000000000 1 hf
tgen ../gen 2310 100000 1000000000000 1 hg
tgen ../gen 12344 100000 1000000000000 1 hh
tgen ../gen 50000 1000000000000 1000000000000 1 hi
tgen ../gen 70000 100000 1000000000000 1 hj
tgen ../gen 100000 100000 1000000000000 1 hk
tgen ../gen 100000 100000 1000000000000 1 hl
tgen ../gen 100000 100000 1000000000000 1 hm
tgen ../gen 100000 1000000000 1000000000000 1 hn
tgen ../gen 100000 1000000000000 1000000000000 1 ho
tgen ../gen 100000 1000000000000 1000000000000 1 hp
tgen ../gen 100000 100000000000 1000000000000 1 hq
tgen ../gen 100000 1000000000000 1000000000000 1 hr
tgen ../gen 100000 1000000000000 1000000000000 0 hs
tgen ../gen 4 1000000000000 1000000000000 1 ht
tgen ../gen 3 1000000000000 1000000000000 1 hu
tgen ../gen 2 1000000000000 1000000000000 1 iv
tgen ../gen 3 3 1000000000000 1 hw
tgen ../gen 1 1 1000000000000 1 hx

}
