#!/bin/bash

build=$1

DIRECTORY=./_build
if [ ! -d "$DIRECTORY" ]; then
	mkdir "$DIRECTORY"
fi

cd "$DIRECTORY"
if [ "$build" == "release" ]; then
	cmake ../ -DBUILD_DOCUMENTATION=ON -DCMAKE_BUILD_TYPE=Release -G "Sublime Text 2 - Unix Makefiles"
else
	cmake ../ -DBUILD_DOCUMENTATION=ON -DCMAKE_BUILD_TYPE=Debug -G "Sublime Text 2 - Unix Makefiles"
fi
make all
cd ..
