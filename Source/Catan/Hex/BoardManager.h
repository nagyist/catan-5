// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <array>
#include <random>
#include "ResourceType.h"

class AHexagonTile;
class ACatanGameState;
class AHexagonTile;
class ARoad;

/**
 * 
 */
class CATAN_API BoardManager
{
public:
	BoardManager(long long seed, ACatanGameState* gamestate);
    ~BoardManager();

    void BuildMap(UWorld* world);
    AHexagonTile* ClosestTile(const FVector& position) const;
    ARoad* ClosestRoad(const FVector& position) const;
    FVector ClosestCorner(const FVector& position) const;

private:
    void RandomizeResources(std::default_random_engine& rand);
    void RandomizeNumberTokens(std::default_random_engine& rand);
    void BuildRoads(const AHexagonTile& tile, UWorld* world);

    std::array<ResourceType, 19> remaining_resources_;
    std::array<uint16, 18> numbertokens_;
    ACatanGameState* gamestate_;
};
