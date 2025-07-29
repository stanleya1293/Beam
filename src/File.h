#ifndef FILE_H
#define FILE_H

namespace Beam {
	class File {
	public:
		virtual ~File() = default;
		virtual void writeRGB(int r, int g, int b) const;
	};

	class FilePPM : public File {
	public:
		void writeRGB(int r, int g, int b) const override;	
	};
}

#endif
