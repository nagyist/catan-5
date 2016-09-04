// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <memory>
#include <unordered_map>
#include <array>
#include <random>
#include "ResourceType.h"


class ARoad;
class AHexagonTile;

/**
 * 
 */
class CATAN_API BoardManager
{
public:
	BoardManager(long long seed);
    ~BoardManager();

    void BuildMap(UWorld* world);

private:
    void RandomizeResources(std::default_random_engine& rand);
    void RandomizeNumberTokens(std::default_random_engine& rand);
    void BuildRoads(const AHexagonTile& tile, UWorld* world);

    struct FVectorHash
    {
        std::size_t operator()(const FVector& v) const
        {
            std::size_t result = std::hash<float>()(v.X);
            result = (result * 397) ^ std::hash<float>()(v.Y);
            result = (result * 397) ^ std::hash<float>()(v.Z);
            return result;
        }
    };

    struct FVectorEqual
    {
        bool operator()(const FVector& lhs, const FVector& rhs) const
        {
            return lhs.Equals(rhs);
        }
    };

    std::unordered_map < FVector, AHexagonTile*, FVectorHash, FVectorEqual> tiles_;
    std::unordered_map < FVector, ARoad*, FVectorHash, FVectorEqual> roads_;

    std::array<ResourceType, 19> remaining_resources_;
    std::array<uint16, 18> numbertokens_;
};
