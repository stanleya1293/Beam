#include "Raytracer.h"
#include "Object.h"
#include "File.h"

int main(int argc, char* argv[]) {
	Beam::Raytracer rt;
	Beam::Object sphere;
	Beam::File output;

	rt.RenderToFile(sphere, output);

	return 0;
}