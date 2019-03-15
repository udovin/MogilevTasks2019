#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from setuptools import setup, find_packages


setup(
	name="pyjudge",
	version="0.0.1",
	author="Ivan Udovin",
	packages=find_packages(),
	install_requires=(
		"requests",
		"Flask",
	),
)
