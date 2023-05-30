rm -rf build-linux-debug

cmake -S . -B build-linux-debug -DCMAKE_BUILD_TYPE=Debug
