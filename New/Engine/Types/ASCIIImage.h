//=============================================================================================

#ifndef ENGINE_TYPE_ASCIIIMAGE_H
#define ENGINE_TYPE_ASCIIIMAGE_H

//=============================================================================================

#include <string>
#include <vector>

//=============================================================================================

class ASCIIImage
{
public:
	ASCIIImage();
	ASCIIImage(std::initializer_list<std::string> lines);
	~ASCIIImage();

public:
	const std::vector<std::string> GetLines() const { return Lines; }

	const std::string ToString() const;

private:
	std::vector<std::string> Lines;

};

//=============================================================================================

#endif

//=============================================================================================