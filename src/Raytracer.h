#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Object.h"
#include "File.h"

namespace Beam {
	class Raytracer {
	public:
		Raytracer();
		~Raytracer();
		void RenderToFile(const Object& scene, const File& output);
	private:
		
	};
}

#endif
