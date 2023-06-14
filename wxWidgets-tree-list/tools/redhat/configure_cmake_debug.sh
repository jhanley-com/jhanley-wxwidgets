rm -rf build/redhat-debug

cmake -S . -B build/redhat-debug -DCMAKE_BUILD_TYPE=Debug -DREDHAT=1
