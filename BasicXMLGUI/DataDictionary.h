// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef DataDictionary_IncludeGuard
#define DataDictionary_IncludeGuard

#include "tsl\ordered_map.h"//Ordered map from https://github.com/Tessil/ordered-map
#include "DataNode.h"

/// <summary>
/// Class named DataDictionary.
/// Implements the <see cref="std::unordered_map{std::string, DataNode}" />
/// </summary>
/// <seealso cref="std::unordered_map{std::string, DataNode}" />
class DataDictionary : public tsl ::ordered_map<std::string, DataNode>
{
public:
    /// <summary>
    /// Use insert if doesn't Already exist, otherwise set the value
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void Add(std::string Key, DataNode Value)
    {//https://stackoverflow.com/questions/31792229/how-to-set-a-value-in-an-unordered-map-and-find-out-if-a-new-key-was-added
        auto p = this->insert({ Key, Value });
        if (!p.second) {
            // overwrite previous value
            p.first->second = Value;
        }
    }
    /// <summary>
    /// Adds the only Values for keys that don't exist yet
    /// </summary>
    /// <param name="First">The first.</param>
    /// <param name="Second">The second.</param>
    bool AddOnlyNew(std::string Key, DataNode Value)
    {
        std::pair<std::string, DataNode> Value = { First, Second };
        auto p = this->insert(Value);
        if (p.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    /// <summary>
    /// Initializes a new instance of the <see cref="DataDictionary"/> class.
    /// </summary>
    DataDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="DataDictionary"/> class.
    /// </summary>
    ~DataDictionary() {}
};
#endif