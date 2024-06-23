#pragma once
enum EasingType
{
	Linear,
	EaseInQuadratic,
	EaseOutQuadratic,
	EaseInOutQuadratic,
	EaseInCubic,
	EaseOutCubic,
	EaseInOutCubic,
	EaseInQuart,
	EaseOutQuart,
	EaseInOutQuart,
	EaseInQuint,
	EaseOutQuint,
	EaseInOutQuint,
	EaseInSine,
	EaseOutSine,
	EaseInOutSine,
	EaseInExpo,
	EaseOutExpo,
	EaseInOutExpo,
	EaseInCirc,
	EaseOutCirc,
	EaseInOutCirc,
	EaseInBack,
	EaseOutBack,
	EaseInOutBack,
	EaseInBounce,
	EaseOutBounce,
	EaseInOutBounce
};
class Easing
{
public:
	static float Ease(EasingType type, float a, float b, float t);
	static float Linear(float a, float b, float t);
	static float EaseInQuadratic(float a, float b, float t);
	static float EaseInQuadratic(float t);
	static float EaseOutQuadratic(float a, float b, float t);
	static float EaseOutQuadratic(float t);
	static float EaseInOutQuadratic(float a, float b, float t);
	static float EaseInOutQuadratic(float t);
	static float EaseInCubic(float a, float b, float t);
	static float EaseInCubic(float t);
	static float EaseOutCubic(float a, float b, float t);
	static float EaseOutCubic(float t);
	static float EaseInOutCubic(float a, float b, float t);
	static float EaseInOutCubic(float t);
	static float EaseInQuart(float a, float b, float t);
	static float EaseInQuart(float t);
	static float EaseOutQuart(float a, float b, float t);
	static float EaseOutQuart(float t);
	static float EaseInOutQuart(float a, float b, float t);
	static float EaseInOutQuart(float t);
	static float EaseInQuint(float a, float b, float t);
	static float EaseInQuint(float t);
	static float EaseOutQuint(float a, float b, float t);
	static float EaseOutQuint(float t);
	static float EaseInOutQuint(float a, float b, float t);
	static float EaseInOutQuint(float t);
	static float EaseInSine(float a, float b, float t);
	static float EaseInSine(float t);
	static float EaseOutSine(float a, float b, float t);
	static float EaseOutSine(float t);
	static float EaseInOutSine(float a, float b, float t);
	static float EaseInOutSine(float t);
	static float EaseInExpo(float a, float b, float t);
	static float EaseInExpo(float t);
	static float EaseOutExpo(float a, float b, float t);
	static float EaseOutExpo(float t);
	static float EaseInOutExpo(float a, float b, float t);
	static float EaseInOutExpo(float t);
	static float EaseInCirc(float a, float b, float t);
	static float EaseInCirc(float t);
	static float EaseOutCirc(float a, float b, float t);
	static float EaseOutCirc(float t);
	static float EaseInOutCirc(float a, float b, float t);
	static float EaseInOutCirc(float t);
	static float EaseInBack(float a, float b, float t);
	static float EaseInBack(float t);
	static float EaseOutBack(float a, float b, float t);
	static float EaseOutBack(float t);
	static float EaseInOutBack(float a, float b, float t);
	static float EaseInOutBack(float t);
	static float EaseInBounce(float a, float b, float t);
	static float EaseInBounce(float t);
	static float EaseOutBounce(float a, float b, float t);
	static float EaseOutBounce(float t);
	static float EaseInOutBounce(float a, float b, float t);
	static float EaseInOutBounce(float t);
};