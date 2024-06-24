//=============================================================================================

#ifndef ENGINE_TYPES_DELEGATE_SINGLE_H
#define ENGINE_TYPES_DELEGATE_SINGLE_H

//=============================================================================================

#include <string>
#include <functional>

//=============================================================================================

template<typename... PARAMS>
class SingleDelegate
{
public:
	SingleDelegate(){ }
	~SingleDelegate(){ }

	//=== Types =============================================================
public:
	typedef std::function<void(PARAMS...)> FunctionType;

	//=== General ===========================================================
public:
	void Broadcast(PARAMS... params) const { Function(params...); }
	//void operator()() const { Broadcast(); }

	const void Bind(FunctionType function) { Function = function; }
	const void Unbind() { FunctionType = []() {}; }

private:
	FunctionType Function;

};

//=============================================================================================


//=============================================================================================

#endif

//=============================================================================================