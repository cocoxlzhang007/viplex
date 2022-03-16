cp test.png ../../../bin/
cp publicnetdemo.cpp ../../../bin/
cd ../../../bin
g++ -fPIC -Wl,-rpath . -std=c++11 publicnetdemo.cpp -I"../include" -L"." -l"viplexcore"  -l"Qt5Core" -o publicnetdemo -pthread
./publicnetdemo
