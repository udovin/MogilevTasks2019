#!/bin/sh

docker run -v "$(realpath .)":/data blang/latex pdflatex contests/week1/day1/statements.tex
