//=============================================================================================

#ifndef ENGINE_TYPES_DELEGATE_MULTI_H
#define ENGINE_TYPES_DELEGATE_MULTI_H

//=============================================================================================

#include <string>
#include <sstream>
#include <map>
#include <functional>

#include "DelegateHandle.h"

//=============================================================================================

template<typename... PARAMS>
class MultiDelegate
{
public:
	MultiDelegate() { }
	~MultiDelegate() { Functions.clear(); }

	//=== Types =============================================================
public:
	typedef std::function<void(PARAMS...)> FunctionType;

	//=== General ===========================================================
public:
	void Broadcast(PARAMS... params) const
	{
		for (const std::pair<std::string, FunctionType>& func : Functions)
		{
			func.second(params...);
		}
	}
	//void operator()() const { Broadcast(); }

	const DelegateHandle Bind(FunctionType function)
	{
		std::stringstream ss;
		ss << "BoundFunction#" << Counter;
		++Counter;

		DelegateHandle handle(ss.str());

		Functions[handle.GetIdentifier()] = function;

		return handle;
	}

	const bool Unbind(DelegateHandle handle)
	{
		std::map<std::string, FunctionType>::iterator it = Functions.find(handle.GetIdentifier());
		if (it != Functions.end())
		{
			Functions.erase(it);
			return true;
		}
		return false;
	}

	void UnbindAll() { Functions.clear(); }

private:
	std::map<std::string, FunctionType> Functions;
	int Counter = 0;

};

//=============================================================================================

#endif

//=============================================================================================