bin/programa : src/main.cpp include/Foco.hpp
	c++ src/main.cpp -o bin/programa -I include

run: bin/animacion
	./bin/animacion

bin/animacion: src/animacion.cpp src/escena.cpp include/escena.hpp
	@mkdir -p bin
	g++ -Iinclude src/animacion.cpp src/escena.cpp -o bin/animacion -pthread
