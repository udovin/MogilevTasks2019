#!/bin/sh

rm -rf venv
python3 -m venv venv
. venv/bin/activate
pip install -U pip
echo 'Now you can use:'
echo '$ . venv/bin/activate'
echo
