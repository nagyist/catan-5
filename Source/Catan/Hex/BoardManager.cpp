// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include <algorithm>
#include <random>
#include <chrono>

#include "BoardManager.h"
#include "HexagonTile.h"
#include "Road.h"
#include "Orientation.h"
#include "HexUtils.h"

BoardManager::BoardManager(long long seed)
{
    auto rand = std::default_random_engine(seed);
    RandomizeResources(rand);
    RandomizeNumberTokens(rand);
}

BoardManager::~BoardManager()
{
}

void BoardManager::BuildMap(UWorld* world)
{
    int tile_index = 0;
    int number_token_index = 0;
    for (int j = 0, r = -2; j < 5; ++j, ++r)
    {
        for (int i = 0, q = -2; i < 5; ++i, ++q)
        {
            if ((j == 0 && i == 0) ||
                (j == 0 && i == 1) ||
                (j == 1 && i == 0) ||
                (j == 3 && i == 4) ||
                (j == 4 && i == 3) ||
                (j == 4 && i == 4))
            {
                continue;
            }

            auto axialcoordinate = FVector2D(q, r);
            auto cubecoordinate = HexUtils::CubeCoord(axialcoordinate);

            FVector2D translation = PointOrientation.TransformVector(axialcoordinate);
            translation.X = translation.X * AHexagonTile::Size;
            translation.Y = translation.Y * AHexagonTile::Size;
            /*wchar_t buffer[100];
            swprintf_s(buffer, L"X: %f, Y: %f, tX: %f, tY: %f", hex->X, hex->Y, translation.X, translation.Y);
            GEngine->AddOnScreenDebugMessage(-1, 50, FColor::Red, *FString(buffer));*/
            auto tile = world->SpawnActor<AHexagonTile>(AHexagonTile::StaticClass(), FVector(translation, 0), FRotator::ZeroRotator);
            tile->SetResourceType(remaining_resources_[tile_index++]);
            tile->SetCoordinates(cubecoordinate);
            if (tile->GetResourceType() != Desert)
            {
                tile->SetDiceRollValue(numbertokens_[number_token_index++]);
            }
            tiles_[cubecoordinate] = tile;

            BuildRoads(*tile, world);
        }
    }
}

/*
Find the closest HexagonTile based on actor location (as opposed to bounds or collision detection)
*/
AHexagonTile* BoardManager::ClosestTile(const FVector& position) const
{
    AHexagonTile* closesttile = nullptr;
    float closestdistance = std::numeric_limits<float>::max();
    for (auto& tile : this->tiles_) {
        auto dist = (tile.second->GetActorLocation() - position).Size();
        if (dist < closestdistance) {
            closestdistance = dist;
            closesttile = tile.second;
        }
    }

    return closesttile;
}

ARoad* BoardManager::ClosestRoad(const FVector& position) const
{
    return nullptr;
}

FVector BoardManager::ClosestCorner(const FVector& position) const
{
    auto hextile = ClosestTile(position);

    FVector closestcorner;
    float closestdistance = std::numeric_limits<float>::max();
    for (int i = 0; i < 6; ++i) {
        FVector corner = HexUtils::GetCorner(hextile->GetActorLocation(), i);
        auto dist = (corner - position).Size();
        if (dist < closestdistance) {
            closestdistance = dist;
            closestcorner = corner;
        }
    }

    return closestcorner;
}

void BoardManager::RandomizeResources(std::default_random_engine& rand)
{
    remaining_resources_[0] = ResourceType::Brick;
    remaining_resources_[1] = ResourceType::Brick;
    remaining_resources_[2] = ResourceType::Brick;

    remaining_resources_[3] = ResourceType::Ore;
    remaining_resources_[4] = ResourceType::Ore;
    remaining_resources_[5] = ResourceType::Ore;

    remaining_resources_[6] = ResourceType::Wheat;
    remaining_resources_[7] = ResourceType::Wheat;
    remaining_resources_[8] = ResourceType::Wheat;
    remaining_resources_[9] = ResourceType::Wheat;

    remaining_resources_[10] = ResourceType::Wood;
    remaining_resources_[11] = ResourceType::Wood;
    remaining_resources_[12] = ResourceType::Wood;
    remaining_resources_[13] = ResourceType::Wood;

    remaining_resources_[14] = ResourceType::Wool;
    remaining_resources_[15] = ResourceType::Wool;
    remaining_resources_[16] = ResourceType::Wool;
    remaining_resources_[17] = ResourceType::Wool;

    remaining_resources_[18] = ResourceType::Desert;

    std::shuffle(remaining_resources_.begin(), remaining_resources_.end(), rand);
}

void BoardManager::RandomizeNumberTokens(std::default_random_engine& rand)
{
    numbertokens_[0] = 2;
    for (int i = 1; i < (6 - 2) * 2 + 1; i++)
    {
        numbertokens_[i] = (i - 1) / 2 + 3;
    }

    for (int i = (6 - 2) * 2 + 1; i < 17; i++)
    {
        numbertokens_[i] = (i - 1) / 2 + 4;
    }
    numbertokens_[17] = 12;

    std::shuffle(numbertokens_.begin(), numbertokens_.end(), rand);
}

void BoardManager::BuildRoads(const AHexagonTile& tile, UWorld* world)
{
    for (int i = 0; i < 6; ++i)
    {
        auto address = HexUtils::GetEdge(tile.GetCoordinates(), i);
        if (roads_.find(address) == roads_.end())
        {
            FVector2D translation = PointOrientation.TransformVector(HexUtils::AxialCoord(address));
            translation.X = translation.X * AHexagonTile::Size;
            translation.Y = translation.Y * AHexagonTile::Size;
            auto road = world->SpawnActor<ARoad>(ARoad::StaticClass(), FVector(translation, 0), FRotator(0, -60 * i, 0));
            roads_[address] = road;
        }
    }
}
