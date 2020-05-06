// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#if !defined(UIntVector_IncludeGuard)
#define UIntVector_IncludeGuard

#include <vector>

/// <summary>
/// Shortcut to prevent need to construct new derived Vectors for Unsigned Int
/// </summary>
/// <seealso cref="std::vector" />
class UIntVector : public std::vector<unsigned int>
{
public:
	bool DeleteFirstMatch(unsigned int targetVal)
	{
		bool NodeFound = false;
		for (UIntVector::iterator CurrentVal = this->begin(), LastVal = this->end(); CurrentVal != LastVal || NodeFound; ++CurrentVal)
		{
			if (*CurrentVal == targetVal)
			{
				NodeFound = true;
				this->erase(CurrentVal);
			}
		}
		return NodeFound;
	}
};

#endif