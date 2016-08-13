// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "BoardManager.h"
#include "HexagonTile.h"
#include "Orientation.h"
#include <memory>

BoardManager::BoardManager()
{
    this->BuildMap();
}

BoardManager::~BoardManager()
{
}

void BoardManager::SpawnMap(UWorld* world) const
{
    for (const auto& arr : m_map)
    {
        for (const auto& hex : arr)
        {
            if (hex != nullptr)
            {
                FVector2D translation = PointOrientation.TransformVector(*hex.get());
                translation.X = translation.X * AHexagonTile::Size;
                translation.Y = translation.Y * AHexagonTile::Size;
                /*wchar_t buffer[100];
                swprintf_s(buffer, L"X: %f, Y: %f, tX: %f, tY: %f", hex->X, hex->Y, translation.X, translation.Y);
                GEngine->AddOnScreenDebugMessage(-1, 50, FColor::Red, *FString(buffer));*/
                world->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector(translation, 0), FRotator::ZeroRotator);
            }
        }
    }
}

void BoardManager::BuildMap()
{
    for (int j = 0, r = -2; j < 5; ++j, ++r)
    {
        for (int i = 0, q = -2; i < 5; ++i, ++q)
        {
            m_map[j][i] = std::make_unique<FVector2D>(q, r);
        }
    }

    m_map[0][0] = nullptr;
    m_map[0][1] = nullptr;
    m_map[1][0] = nullptr;

    m_map[3][4] = nullptr;
    m_map[4][3] = nullptr;
    m_map[4][4] = nullptr;
}
