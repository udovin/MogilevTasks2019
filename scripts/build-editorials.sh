#!/bin/sh

build() {
	docker run -v "$(realpath .)":/data blang/latex pdflatex \
		--output-directory "$1" "$1/editorials.tex"
}

build "contests/week1/day1"
