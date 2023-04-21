#!/bin/bash

echo "creating build directory"
if [ -d build ]; then
	echo "build directory exists cleaning the contents"
else
	mkdir build
fi

echo "running franca interface generator"
cd build

../cgen/commonapi_core_generator/commonapi-core-generator-linux-x86_64 -sk ../fidl/*.fidl
../cgen/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64 ../fidl/*.fdepl

echo "interface generation done"

cmake ..

make install

echo "done"
