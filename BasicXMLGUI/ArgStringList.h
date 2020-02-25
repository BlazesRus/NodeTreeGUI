// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef ArgStringList_IncludeGuard
#define ArgStringList_IncludeGuard

#include <string>

class ArgStringList : public vertex < std::string >
{
private:
	//	bool FileStreamOpen = false;
public:
	ArgStringList()
	{
	
	}
	void LoadArgs(std::string Content)
	{
		//if(!isEmpty())
		//{
		//	this->clear();
		//}
		string CurrentElement = "";
		for(vector<char>::iterator CurrentChar = this.begin(); Arg != this.end(); ++CurrentChar) 
		{
			if(CurrentElement == "")
			{
				if(*CurrentChar != '\n'&&*CurrentChar != ' '&&*CurrentChar != '\t'&&*CurrentChar != '	')
				{
					CurrentElement = *CurrentChar;
				}
			}
			else
			{
				if(*CurrentChar != '\n'&&*CurrentChar != ' '&&*CurrentChar != '\t'&&*CurrentChar != '	')
				{
					CurrentElement += *CurrentChar;
				}
				else if(*CurrentChar != ',')
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
		string ConvertedString = "\"";
		for(vector<std::string>::iterator Element = this.begin(); Element != this.end(); ++Element) 
		{
			if(i != this.begin())
			{
				ConvertedString += ",";
			}
			ConvertedString += *Element;
		}
		ConvertedString += "\"";
		return ConvertedString;
	}
};
#endif