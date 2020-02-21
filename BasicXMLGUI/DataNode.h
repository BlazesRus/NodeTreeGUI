// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#if !defined(DataNode_IncludeGuard)
#define DataNode_IncludeGuard

#include "ArgList.h"
#include "VariableTypeLists.h"

/// <summary>
/// Class named DataNode. (Node links to other nodes in node bank)
/// Held within NodeDictionary with int key
/// </summary>
class DataNode
{public:
	/// <summary>
	/// Index position of ParentNode (EmptyNode=inside Root Level by default)
	/// </summary>
	int ParentIndex;
	
	/// <summary>
	/// The indexes of all child nodes
	/// </summary>
	XIntegerList ChildNodes;

	std::string TagName;
	
	ArgList ArgData;
	ArgStringList TagContent;

	/// <summary>
	/// The b open
	/// </summary>
	BOOL    bOpen;
public:
/*    /// <summary>
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
	}*/
	
	/// <summary>
	/// Initializes a new instance of the <see cref="DataNode"/> class. (All Data Nodes must have display names)
	/// </summary>
	/// <param name="name">The NodeName.</param>
	DataNode(std::string name, int nodeKey)
	{
		TagName = name;
		rNode.SetRectEmpty();
		bOpen = TRUE;
		NodeType = 0;
		nDisp.NodeKey = nodeKey;
	}
	
	/// <summary>
	/// Initializes a new instance of the <see cref="DataNode"/> class.
	/// </summary>
	/// <param name="name">The NodeName.</param>
	DataNode(std::string name, short nodeType, int nodeKey)
	{
		TagName = name;
		rNode.SetRectEmpty();
		bOpen = TRUE;
		NodeType = nodeType;
		NodeKey = nodeKey;
	}
	
	/// <summary>
	/// Finalizes an instance of the <see cref="DataNode"/> class.
	/// </summary>
	~DataNode()
	{

	}
};