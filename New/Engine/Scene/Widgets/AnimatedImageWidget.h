//=============================================================================================

#ifndef ENGINE_WIDGET_ANIMATEDIMAGE_H
#define ENGINE_WIDGET_ANIMATEDIMAGE_H

//=============================================================================================

#include "../Widget.h"

//=============================================================================================

#include <vector>

#include "../../Types/ASCIIImage.h"
#include "../Components/TimerComponent.h"

//=============================================================================================

struct Keyframe
{
	float Time;
	ASCIIImage Frame;

	Keyframe(float time, ASCIIImage frame)
		: Time(time), Frame(frame)
	{ }

};

//=============================================================================================

class AnimatedImageWidget : public Widget
{
public:
	AnimatedImageWidget();
	AnimatedImageWidget(std::vector<Keyframe> keyframes, bool looping = false);
	~AnimatedImageWidget();

	//=== General ===========================================================
public:
	virtual void Update(float deltaTime) override;
	virtual const std::string Render() override;

	//=== Animation =========================================================
public:
	void SetKeyframes(std::initializer_list<Keyframe> keyframes) { Keyframes = keyframes; }
	void SetLooping(bool state) { Looping = state; }

	void PlayAnimation();
	void StopAnimation();

	void SetFrame(int index);

	const bool IsPlaying() const { return PlayingAnimation; }
	const bool IsLooped() const { return Looping; }

	const float GetElapsedTime() const { return Timer->GetElapsedTime(); }

private:
	std::vector<Keyframe> Keyframes;
	int CurrentFrame;
	bool PlayingAnimation;
	bool Looping;

	TimerComponent* Timer;

};

//=============================================================================================

#endif

//=============================================================================================