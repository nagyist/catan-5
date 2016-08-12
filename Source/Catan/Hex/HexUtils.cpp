// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "HexUtils.h"

FVector2D HexUtils::AxialCoord(FVector cube)
{
    return FVector2D(cube.X, cube.Z);
}

FVector HexUtils::CubeCoord(FVector2D axial)
{
    return FVector(axial.X, -axial.X - axial.Y, axial.Y);
}

FVector HexUtils::GetCubeDirection(int direction)
{
    return cubeDirs[direction];
}

FVector2D HexUtils::GetAxialDirection(int direction)
{
    return axialDirs[direction];
}

FVector2D HexUtils::GetNeighbor(FVector2D hex, int direction)
{
    return hex + GetAxialDirection(direction);
}

FVector HexUtils::GetNeighbor(FVector hex, int direction)
{
    return hex + GetCubeDirection(direction);
}

HexUtils::HexUtils()
{
}

HexUtils::~HexUtils()
{
}

const FVector HexUtils::cubeDirs[] = {
    FVector(1, -1, 0), FVector(1, 0, -1), FVector(0, 1, -1),
    FVector(-1, 1, 0), FVector(-1, 0, 1), FVector(0, -1, 1)
};

const FVector2D HexUtils::axialDirs[] = {
    FVector2D(1, 0), FVector2D(1, -1), FVector2D(0, -1),
    FVector2D(-1, 0), FVector2D(-1, 1), FVector2D(0, 1)
};