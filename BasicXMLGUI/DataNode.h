// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#if !defined(BasicDataNode_IncludeGuard)
#define BasicDataNode_IncludeGuard

#include "ArgList.h"
#include "VariableTypeLists.h"

/// <summary>
/// Class named BasicDataNode(derive into DataNode subclass into view). (Node links to other nodes in node bank)
/// Held within NodeDictionary with int key
/// </summary>
class BasicDataNode
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
	/// <summary>
	/// Initializes a new instance of the <see cref="DataNode"/> class. (All Data Nodes must have display names)
	/// </summary>
	/// <param name="name">The NodeName.</param>
	DataNode(std::string name)
	{
		TagName = name;
		rNode.SetRectEmpty();
		bOpen = TRUE;
		NodeType = 0;
	}
	
	/// <summary>
	/// Finalizes an instance of the <see cref="DataNode"/> class.
	/// </summary>
	~DataNode(){}
};

class ClassicDataNode : BasicDataNode
{
public:
	/// <summary>
	/// The r node
	/// </summary>
	CRect		rNode;
	
	////0 = Default
	////1 = EventNode
	////2 = VariableNode
	////3 = Character Property
	////10 = Node Link
	////11 = EventNode Link
	////12 = VariableNode Link
	////13 = Character Property Link
	//short NodeType;
	
	/// <summary>
	/// Initializes a new instance of the <see cref="BhvDataNode"/> class.
	/// </summary>
	/// <param name="name">The NodeName.</param>
	ClassicDataNode(std::string name)
	{
		rNode.SetRectEmpty();
	}
	
	~ClassicDataNode(){}
};