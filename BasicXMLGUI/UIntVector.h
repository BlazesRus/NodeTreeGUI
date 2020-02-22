// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#if !defined(UIntVector_IncludeGuard)
#define UIntVector_IncludeGuard

/// <summary>
/// Shortcut to prevent needed to construct new templated Vectors for Unsigned Int
/// </summary>
/// <seealso cref="std::vector" />
class UIntVector : std::vector<unsigned int>
{public:
	bool DeleteFirstMatch(unsigned int targetVal)
	{
		bool NodeFound = false;
		for(UIntVector::iterator Index = this.begin(), EndIndex = this.end(); Index != EndIndex||NodeFound; ++Index)
		{
			if(*Index==targetVal)
			{
				NodeFound = true;
				this->erase(*Index);
			}
		}
		return NodeFound;
	}
}

#endif