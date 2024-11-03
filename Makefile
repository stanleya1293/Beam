default: 
	cmake -S. -B./build
	make -C ./build
	./build/Beam
