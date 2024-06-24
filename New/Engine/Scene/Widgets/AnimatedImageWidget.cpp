//=============================================================================================

#include "AnimatedImageWidget.h"

//=============================================================================================

AnimatedImageWidget::AnimatedImageWidget()
	: Widget(), CurrentFrame(0), PlayingAnimation(false), Looping(false)
{ 
	Timer = AddComponent<TimerComponent>();
}
AnimatedImageWidget::AnimatedImageWidget(std::vector<Keyframe> keyframes, bool looping)
	: Widget(), Keyframes(keyframes), CurrentFrame(0), PlayingAnimation(false), Looping(looping)
{
	Timer = AddComponent<TimerComponent>();
}

//=============================================================================================

AnimatedImageWidget::~AnimatedImageWidget()
{ }

//=============================================================================================

void AnimatedImageWidget::Update(float deltaTime)
{
	Widget::Update(deltaTime);

	if (PlayingAnimation)
	{
		int lookAhead = (CurrentFrame + 1);
		if (Keyframes[lookAhead].Time <= Timer->GetElapsedTime())
		{
			++CurrentFrame;
		}

		if (CurrentFrame == (Keyframes.size() - 1))
		{
			if (Looping)
			{
				CurrentFrame = 0;
				Timer->Reset();
			}
			else
			{
				StopAnimation();
			}
		}
	}
}

//=============================================================================================

const std::string AnimatedImageWidget::Render()
{
	if (Keyframes.size() > 0)
	{
		return Keyframes[CurrentFrame].Frame.ToString();
	}
	return "";
}

//=============================================================================================

void AnimatedImageWidget::PlayAnimation()
{
	if (Keyframes.size() > 0)
	{
		PlayingAnimation = true;

		CurrentFrame = 0;
		Timer->Start();
	}
}

//=============================================================================================

void AnimatedImageWidget::StopAnimation()
{
	Timer->Stop();

	PlayingAnimation = false;
}

//=============================================================================================

void AnimatedImageWidget::SetFrame(int frame)
{
	if (frame >= 0 && frame < Keyframes.size())
	{
		CurrentFrame = frame;
		Timer->Set(Keyframes[CurrentFrame].Time);
	}
}

//=============================================================================================