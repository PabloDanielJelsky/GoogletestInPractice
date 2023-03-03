cmake . => to generate build files
make => to build the project

To keep it clean and create all the deliveries in build sub-directory
1)	cmake -S . -B build && cmake --build build
2)	cmake -Bbuild -DCMAKE_BUILD_TYPE=Debug && cd build && make
2.1)	To run test:			make test or ctest
