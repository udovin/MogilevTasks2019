#!/bin/sh

build() {
	docker run -v "$(realpath .)":/data blang/latex pdflatex \
		--output-directory "$1" "$1/statements.tex"
}

build "contests/week1/day1"
build "contests/week1/day2"
