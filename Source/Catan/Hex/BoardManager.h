// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <memory>
#include <unordered_map>


class ARoad;
class AHexagonTile;

/**
 * 
 */
class CATAN_API BoardManager
{
public:
	BoardManager();
	~BoardManager();

    void BuildMap(UWorld* world);

private:
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

    struct PairFVectorHash
    {
        std::size_t operator()(const std::pair<FVector, FVector> p) const
        {
            FVectorHash hash;
            std::size_t result = hash(p.first);
            result = (result * 397) ^ hash(p.second);
            return result;
        }
    };

    struct PairFVectorEqual
    {
        bool operator()(const std::pair<FVector, FVector>& lhs, const std::pair<FVector, FVector>& rhs) const
        {
            return lhs.first.Equals(rhs.first) && lhs.second.Equals(rhs.second);
        }
    };

    std::unordered_map < FVector, AHexagonTile*, FVectorHash, FVectorEqual> tiles_;
    std::unordered_map < std::pair<FVector, FVector>, ARoad*, PairFVectorHash, PairFVectorEqual> roads_;
};
