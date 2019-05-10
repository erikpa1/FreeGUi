#pragma once

template<typename T>
T divide_with_zero(T first, T second, T ifZero)
{
	if (second != 0)
	{
		return first / second;
	}
	else
	{
		return ifZero;
	}
}

