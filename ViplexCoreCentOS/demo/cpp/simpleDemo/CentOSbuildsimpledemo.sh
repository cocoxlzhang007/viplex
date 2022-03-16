cp test.png ../../../bin/
cp main.cpp ../../../bin/
cd ../../../bin
g++ -fPIC -Wl,-rpath . -std=c++11 main.cpp -I"../include" -L"." -l"viplexcore"  -o main -pthread
./main
