rm -rf build/redhat-release

cmake -S . -B build/redhat-release -DCMAKE_BUILD_TYPE=Release -DREDHAT=1
