// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef ArgStringList_IncludeGuard
#define ArgStringList_IncludeGuard

#include <string>
#include <vector>

class ArgStringList : public std::vector < std::string >
{
public:
	ArgStringList()
	{
	
	}
	void LoadArgs(const std::string &Content)
	{
		//if(!isEmpty())
		//{
		//	this->clear();
		//}
		std::string CurrentElement = "";
		for(char const &CurrentChar: Content)
		{
			if(CurrentElement == "")
			{
				if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t')
				{
					CurrentElement = CurrentChar;
				}
			}
			else
			{
				if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t')
				{
					CurrentElement += CurrentChar;
				}
				else if(CurrentChar != ',')
				{
					push_back(CurrentElement);
					CurrentElement = "";
				}
			}
		}
	}
	ArgStringList(std::string Content): ArgStringList()
	{
		LoadArgs(Content);
	}
    /// <summary>
    /// Implements the operator std::string operator.
    /// </summary>
    /// <returns>The result of the operator.</returns>
    explicit operator std::string()
	{
		std::string ConvertedString = "\"";
		for(vector<std::string>::iterator Arg = this->begin(); Arg != this->end(); ++Arg)
		{
			if(Arg != this->begin())
			{
				ConvertedString += ",";
			}
			ConvertedString += *Arg;
		}
		ConvertedString += "\"";
		return ConvertedString;
	}
};
#endif