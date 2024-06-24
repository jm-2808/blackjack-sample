//=============================================================================================

#ifndef ENGINE_TYPES_DELEGATE_HANDLE_H
#define ENGINE_TYPES_DELEGATE_HANDLE_H

//=============================================================================================

#include <string>

//=============================================================================================

class DelegateHandle
{
public:
	DelegateHandle()
		: Identifier("ERROR"), Valid(false)
	{}

	DelegateHandle(std::string identifier)
		: Identifier(identifier), Valid(true)
	{ }

public:
	const std::string GetIdentifier() const { return Identifier; }
	const bool IsValid() const { return Valid; }

private:
	std::string Identifier;
	bool Valid;
};

//=============================================================================================

#endif

//=============================================================================================