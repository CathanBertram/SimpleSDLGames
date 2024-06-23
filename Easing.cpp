#include "Easing.h"
#define _USE_MATH_DEFINES
#include <cmath>;
float Easing::Ease(EasingType type, float a, float b, float t)
{
	switch (type)
	{
	case EasingType::Linear:
		return Linear(a, b, t);
	case EasingType::EaseInQuadratic:
		return EaseInQuadratic(a, b, t);
	case EasingType::EaseOutQuadratic:
		return EaseOutQuadratic(a, b, t);
	case EasingType::EaseInOutQuadratic:
		return EaseInOutQuadratic(a, b, t);
	case EasingType::EaseInCubic:
		return EaseInCubic(a, b, t);
	case EasingType::EaseOutCubic:
		return EaseOutCubic(a, b, t);
	case EasingType::EaseInOutCubic:
		return EaseInOutCubic(a, b, t);
	case EasingType::EaseInQuart:
		return EaseInQuart(a, b, t);
	case EasingType::EaseOutQuart:
		return EaseOutQuart(a, b, t);
	case EasingType::EaseInOutQuart:
		return EaseInOutQuart(a, b, t);
	case EasingType::EaseInQuint:
		return EaseInQuint(a, b, t);
	case EasingType::EaseOutQuint:
		return EaseOutQuint(a, b, t);
	case EasingType::EaseInOutQuint:
		return EaseInOutQuint(a, b, t);
	case EasingType::EaseInSine:
		return EaseInSine(a, b, t);
	case EasingType::EaseOutSine:
		return EaseOutSine(a, b, t);
	case EasingType::EaseInOutSine:
		return EaseInOutSine(a, b, t);
	case EasingType::EaseInExpo:
		return EaseInExpo(a, b, t);
	case EasingType::EaseOutExpo:
		return EaseOutExpo(a, b, t);
	case EasingType::EaseInOutExpo:
		return EaseInOutExpo(a, b, t);
	case EasingType::EaseInCirc:
		return EaseInCirc(a, b, t);
	case EasingType::EaseOutCirc:
		return EaseOutCirc(a, b, t);
	case EasingType::EaseInOutCirc:
		return EaseInOutCirc(a, b, t);
	case EasingType::EaseInBack:
		return EaseInBack(a, b, t);
	case EasingType::EaseOutBack:
		return EaseOutBack(a, b, t);
	case EasingType::EaseInOutBack:
		return EaseInOutBack(a, b, t);
	case EasingType::EaseInBounce:
		return EaseInBounce(a, b, t);
	case EasingType::EaseOutBounce:
		return EaseOutBounce(a, b, t);
	case EasingType::EaseInOutBounce:
		return EaseInOutBounce(a, b, t);
	default:
		return 0;
	}
}

float Easing::Linear(float a, float b, float t)
{
	return a + (b - a) * t;
}

float Easing::EaseInQuadratic(float a, float b, float t)
{
	return a + (b - a) * EaseInQuadratic(t);
}
float Easing::EaseInQuadratic(float t)
{
	return t * t;
}
float Easing::EaseOutQuadratic(float a, float b, float t)
{
	return a + (b - a) * EaseOutQuadratic(t);
}

float Easing::EaseOutQuadratic(float t)
{
	return 2 * (2 - t);
}
float Easing::EaseInOutQuadratic(float a, float b, float t)
{
	return a + (b - a) * EaseInOutQuadratic(t);
}
float Easing::EaseInOutQuadratic(float t)
{
	return t < 0.5f ? 2 * t * t : -1 + (4 - 2 * t) * t;
}

float Easing::EaseInCubic(float a, float b, float t)
{
	return a + (b - a) * EaseInCubic(t);
}

float Easing::EaseInCubic(float t)
{
	return t * t * t;
}

float Easing::EaseOutCubic(float a, float b, float t)
{
	return a + (b - a) * EaseOutCubic(t);
}

float Easing::EaseOutCubic(float t)
{
	return --t * t * t + 1;
}
float Easing::EaseInOutCubic(float a, float b, float t)
{
	return a + (b - a) * EaseInOutCubic(t);
}

float Easing::EaseInOutCubic(float t)
{
	return t < 0.5f ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1;
}

float Easing::EaseInQuart(float a, float b, float t)
{
	return a + (b - a) * EaseInQuart(t);
}

float Easing::EaseInQuart(float t)
{
	return t * t * t * t;
}
float Easing::EaseOutQuart(float a, float b, float t)
{
	return a + (b - a) * EaseOutQuart(t);
}

float Easing::EaseOutQuart(float t)
{
	return 1 - --t * t * t * t;
}

float Easing::EaseInOutQuart(float a, float b, float t)
{
	return a + (b - a) * EaseInOutQuart(t);
}
float Easing::EaseInOutQuart(float t)
{
	return t < .5 ? 8 * t * t * t * t : 1 - 8 * (--t) * t * t * t;
}

float Easing::EaseInQuint(float a, float b, float t)
{
	return a + (b - a) * EaseInQuint(t);
}

float Easing::EaseInQuint(float t)
{
	return t * t * t * t * t;
}
float Easing::EaseOutQuint(float a, float b, float t)
{
	return a + (b - a) * EaseOutQuint(t);
}

float Easing::EaseOutQuint(float t)
{
	return 1 + --t * t * t * t * t;
}

float Easing::EaseInOutQuint(float a, float b, float t)
{
	return a + (b - a) * EaseInOutQuint(t);
}

float Easing::EaseInOutQuint(float t)
{
	return t < 0.5f ? 16 * t * t * t * t * t : 1 + 16 * (--t) * t * t * t * t;
}

float Easing::EaseInSine(float a, float b, float t)
{
	return a + (b - a) * EaseInSine(t);
}

float Easing::EaseInSine(float t)
{
	return 1 - cos((t * M_PI) * 0.5f);
}
float Easing::EaseOutSine(float a, float b, float t)
{
	return a + (b - a) * EaseOutSine(t);
}

float Easing::EaseOutSine(float t)
{
	return sin((t * M_PI) * 0.5f);
}
float Easing::EaseInOutSine(float a, float b, float t)
{
	return a + (b - a) * EaseInOutSine(t);
}

float Easing::EaseInOutSine(float t)
{
	return -(cos(M_PI * t) - 1) * 0.5f;
}

float Easing::EaseInExpo(float a, float b, float t)
{
	return a + (b - a) * EaseInExpo(t);
}

float Easing::EaseInExpo(float t)
{
	return t == 0 ? 0 : pow(2, 10 * t - 10);
}
float Easing::EaseOutExpo(float a, float b, float t)
{
	return a + (b - a) * EaseOutExpo(t);
}

float Easing::EaseOutExpo(float t)
{
	return t == 1 ? 1 : 1 - pow(2, -10 * t);
}
float Easing::EaseInOutExpo(float a, float b, float t)
{
	return a + (b - a) * EaseInOutExpo(t);
}

float Easing::EaseInOutExpo(float t)
{
	return t == 0 ? 0 :
		t == 1 ? 1 :
		t < 0.5f ? pow(2, 20 * t - 10) * 0.5f :
		(2 - pow(2, -20 * t + 10)) * 0.5f;
}

float Easing::EaseInCirc(float a, float b, float t)
{
	return a + (b - a) * EaseInCirc(t);
}
float Easing::EaseInCirc(float t)
{
	return 1 - sqrt(1 - t * t);
}
float Easing::EaseOutCirc(float a, float b, float t)
{
	return a + (b - a) * EaseOutCirc(t);
}
float Easing::EaseOutCirc(float t)
{
	return sqrt(1 - (t - 1) * (t - 1));
}
float Easing::EaseInOutCirc(float a, float b, float t)
{
	return a + (b - a) * EaseInOutCirc(t);
}
float Easing::EaseInOutCirc(float t)
{
	return t < 0.5f
		? (1 - sqrt(1 - (2 * t) * (2 * t))) * 0.5f
		: (sqrt(1 - (-2 * t + 2) * (-2 * t + 2)) + 1) * 0.5f;
}

float Easing::EaseInBack(float a, float b, float t)
{
	return a + (b - a) * EaseInBack(t);
}
float Easing::EaseInBack(float t)
{
	const float c1 = 1.70158f;
	const float c3 = c1 + 1;
	return c3 * t * t * t - c1 * t * t;
}
float Easing::EaseOutBack(float a, float b, float t)
{
	return a + (b - a) * EaseOutBack(t);
}

float Easing::EaseOutBack(float t)
{
	const float c1 = 1.70158f;
	const float c3 = c1 + 1;
	return 1 + c3 * ((t - 1) * (t - 1) * (t - 1)) + c1 * ((t - 1) * (t - 1));
}
float Easing::EaseInOutBack(float a, float b, float t)
{
	return a + (b - a) * EaseInOutBack(t);
}

float Easing::EaseInOutBack(float t)
{
	const float c1 = 1.70158f;
	const float c2 = c1 * 1.525f;

	return t < 0.5f
		? ((2 * t) * (2 * t) * ((c2 + 1) * 2 * t - c2)) * 0.5f
		: ((2 * t - 2) * (2 * t - 2) * ((c2 + 1) * (t * 2 - 2) + c2) + 2) * 0.5f;
}
float Easing::EaseInBounce(float a, float b, float t)
{
	return a + (b - a) * EaseInBounce(t);
}

float Easing::EaseInBounce(float t)
{
	return 1 - EaseOutBounce(1 - t);
}
float Easing::EaseOutBounce(float a, float b, float t)
{
	return a + (b - a) * EaseOutBounce(t);
}

float Easing::EaseOutBounce(float t)
{
	const float n1 = 7.5625f;
	const float d1 = 2.75f;

	if (t < 1 / d1) {
		return n1 * t * t;
	}
	else if (t < 2 / d1) {
		return n1 * (t -= 1.5f / d1) * t + 0.75f;
	}
	else if (t < 2.5 / d1) {
		return n1 * (t -= 2.25f / d1) * t + 0.9375f;
	}
	else {
		return n1 * (t -= 2.625f / d1) * t + 0.984375f;
	}
}

float Easing::EaseInOutBounce(float a, float b, float t)
{
	return a + (b - a) * EaseInOutBounce(t);
}

float Easing::EaseInOutBounce(float t)
{
	return t < 0.5f
		? (1 - EaseOutBounce(1 - 2 * t)) * 0.5f
		: (1 + EaseOutBounce(2 * t - 1)) * 0.5f;
}


