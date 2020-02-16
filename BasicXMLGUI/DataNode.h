// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#if !defined(DataNode_IncludeGuard)
#define DataNode_IncludeGuard

#include "GlobalCode_IniData/CustomOrderedDictionary.h"

/// <summary>
/// Class named DataNode. (Node can hold other nodes)
/// </summary>
class DataNode
{public:
	CustomOrderedDictionary<std::string,DataNode> NodeBank;
	
	/// <summary>
	/// The node name
	/// </summary>
	std::string DisplayName;
	
	/// <summary>
	/// The r node
	/// </summary>
	CRect		rNode;

	/// <summary>
	/// The b open
	/// </summary>
	BOOL    bOpen;
	
	//0 = Default
	//1 = Category Node
	//2 = EventNode
	//3 = VariableNode
	//4 = Character Property
	//5 = SingleLine Tag Context
	//6 = Multiple Element Tag Context
	//7 = Argument Menu
	//9 = SingleLine End Tag
	//10 = EndTag
	short NodeType;
public:
    /// <summary>
    /// Use insert if doesn't Already exist, otherwise set the value
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void Add(std::string Key)
	{
		NodeBank.Add(Key, new DataNode(Key))
	}
	
    /// <summary>
    /// Use insert if doesn't Already exist, otherwise set the value
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void Add(std::string Key, std::string displayname)
	{
		NodeBank.Add(Key, new DataNode(displayname))
	}
	
    /// <summary>
    /// Use insert if doesn't Already exist, otherwise set the value
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void Add(std::string Key, short nodeType)
	{
		NodeBank.Add(Key, new DataNode(NewNode, nodeType))
	}
	
	/// <summary>
	/// Initializes a new instance of the <see cref="DataNode"/> class. (All Data Nodes must have display names)
	/// </summary>
	/// <param name="name">The NodeName.</param>
	DataNode(std::string displayname)
	{
		DisplayName = displayname;
		rNode.SetRectEmpty();
		bOpen = TRUE;
		NodeType = 0;
	}
	
	/// <summary>
	/// Initializes a new instance of the <see cref="DataNode"/> class.
	/// </summary>
	/// <param name="name">The NodeName.</param>
	DataNode(std::string name, short nodeType)
	{
		DisplayName = name;
		rNode.SetRectEmpty();
		bOpen = TRUE;
		NodeType = nodeType;
	}
	
	/// <summary>
	/// Finalizes an instance of the <see cref="DataNode"/> class.
	/// </summary>
	~DataNode()
	{

	}
};