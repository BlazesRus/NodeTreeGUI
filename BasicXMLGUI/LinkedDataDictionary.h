// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef LinkedDataDictionary_IncludeGuard
#define LinkedDataDictionary_IncludeGuard

#include "tsl\ordered_map.h"//Ordered map from https://github.com/Tessil/ordered-map
#include "LinkedDataNode.h"

/// <summary>
/// Class named LinkedDataDictionary.
/// Implements the <see cref="std::unordered_map{std::string, LinkedDataNode}" />
/// </summary>
/// <seealso cref="std::unordered_map{std::string, LinkedDataNode}" />
class LinkedDataDictionary : public tsl ::ordered_map<std::string, LinkedDataNode>
{
public:
    /// <summary>
    /// Use insert if doesn't Already exist, otherwise set the value
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void Add(std::string Key, LinkedDataNode Value)
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
    bool AddOnlyNew(std::string Key, LinkedDataNode Value)
    {
        std::pair<std::string, LinkedDataNode> Value = { First, Second };
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
    /// Initializes a new instance of the <see cref="LinkedDataDictionary"/> class.
    /// </summary>
    LinkedDataDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="LinkedDataDictionary"/> class.
    /// </summary>
    ~LinkedDataDictionary() {}
};
#endif