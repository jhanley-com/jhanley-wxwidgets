rm -rf build-macos-release

cmake -S . -B build-macos-release -DCMAKE_BUILD_TYPE=Release
