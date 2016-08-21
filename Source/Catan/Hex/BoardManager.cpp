// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "BoardManager.h"
#include "HexagonTile.h"
#include "Road.h"
#include "Orientation.h"
#include "HexUtils.h"

BoardManager::BoardManager()
{
}

BoardManager::~BoardManager()
{
}

void BoardManager::BuildMap(UWorld* world)
{
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
            tile->SetResourceType(ResourceType::Brick);
            tile->SetCoordinates(cubecoordinate);
            tiles_[cubecoordinate] = tile;

            BuildRoads(*tile, world);
        }
    }
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
