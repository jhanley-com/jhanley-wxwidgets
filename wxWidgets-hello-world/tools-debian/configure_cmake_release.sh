rm -rf build-linux-release

cmake -S . -B build-linux-release -DCMAKE_BUILD_TYPE=Release
