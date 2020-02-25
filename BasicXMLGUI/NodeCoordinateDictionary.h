// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef NodeCoordinateDictionary_IncludeGuard
#define NodeCoordinateDictionary_IncludeGuard

#include "CustomDictionary.h"

class XCoordToNode : public CustomOrderedDictionary<int, unsigned int>
{

};

/// <summary>
/// Class named NodeCoordinateDictionary (Y-Coord -> X-Coordinate -> Node Indexes).
/// Implements the <see cref="CustomDictionary" />
/// </summary>
/// <seealso cref="std::unordered_map{unsigned int, DataNode}" />
template <typename DataNode>
class NodeCoordinateDictionary : public CustomOrderedDictionary<int, XCoordToNode<DataNode>>
{

};
#endif