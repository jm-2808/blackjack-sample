//=============================================================================================

#ifndef ENGINE_H
#define ENGINE_H

//=============================================================================================

#include <string>
#include <map>
#include <chrono>
#include <future>

//=============================================================================================

class Engine
{
public:
	Engine();
	~Engine();

	//=== Singleton =========================================================
public:
	static Engine* Get()
	{
		if (StaticInstance == nullptr)
		{
			StaticInstance = new Engine;
		}
		return StaticInstance;
	}

private:
	static Engine* StaticInstance;

	//=== Application =======================================================
public:
	void Run();

	const int GetTargetFPS() const { return TargetFPS; }
	void SetTargetFPS(int fps) { TargetFPS = fps; }

	const float GetFrameTime() const { return (1.0f / TargetFPS); } // in milliseconds (roughly)

private:
	std::future<void> InputThread;

	int TargetFPS;

	//=== Exit ==============================================================
public:
	void RequestExit() { ExitRequested = true; }
	const bool IsRequestingExit() const { return ExitRequested; }

private:
	bool ExitRequested = false;

};

//=============================================================================================

#endif

//=============================================================================================