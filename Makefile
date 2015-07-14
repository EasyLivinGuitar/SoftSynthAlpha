cc=g++
dep=src/wave_writer.cpp src/oscillator.cpp src/player.cpp src/sfx.cpp src/delay.cpp
inc=-I include -I third_party/irrKlang-64bit-1.5.0/include
lib=-L /usr/lib third_party/irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so
flags= -pthread -std=c++0x

all: main start

main: 
	$(cc) src/main.cpp -o build/softsynthalpha $(dep) $(inc) $(lib) $(flags) 

start: 
	./build/softsynthalpha
