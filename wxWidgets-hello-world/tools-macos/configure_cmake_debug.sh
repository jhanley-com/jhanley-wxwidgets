rm -rf build-macos-debug

cmake -S . -B build-macos-debug -DCMAKE_BUILD_TYPE=Debug
