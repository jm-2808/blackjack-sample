//=============================================================================================

#ifndef ENGINE_WIDGETCOMPONENT_TIMER_H
#define ENGINE_WIDGETCOMPONENT_TIMER_H

//=============================================================================================

#include "../WidgetComponent.h"

//=============================================================================================

class TimerComponent : public WidgetComponent
{
public:
	TimerComponent();
	~TimerComponent();

	//=== General ===========================================================
public:
	virtual void Update(float deltaTime) override;

	//=== Timing ============================================================
public:
	void Start(bool reset = true);
	void Stop();

	void Set(float time) { ElapsedTime = time; }

	void Reset();

	const float GetElapsedTime() const { return ElapsedTime; }

private:
	float ElapsedTime;

	bool Timing;

};

//=============================================================================================

#endif

//=============================================================================================