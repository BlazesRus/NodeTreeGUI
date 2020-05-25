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

	/// <summary>
	/// Deletes the first match.
	/// </summary>
	/// <param name="targetVal">The target value.</param>
	/// <returns>bool.</returns>
	bool DeleteFirstMatch(unsigned int targetVal)
	{
		bool NodeFound = false;
		for (UIntVector::iterator CurrentVal = this->begin(), LastVal = this->end(); NodeFound==false && CurrentVal != LastVal; ++CurrentVal)
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