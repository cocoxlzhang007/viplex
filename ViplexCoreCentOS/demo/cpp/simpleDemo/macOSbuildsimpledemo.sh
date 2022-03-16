
 g++ -std=c++11 -fPIC -Wl,-rpath ./ main.cpp -I"../../../include"  -L"../../../bin" -l"viplexcore" -o ../../../bin/main
cp test.png ../../../bin/
cd ../../../bin
./main
