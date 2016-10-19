// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "HexagonTile.h"
#include "HexUtils.h"

FVector2D HexUtils::AxialCoord(const FVector& cube)
{
    return FVector2D(cube.X, cube.Z);
}

FVector HexUtils::CubeCoord(const FVector2D& axial)
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

FVector2D HexUtils::GetNeighbor(const FVector2D &hex, int direction)
{
    return hex + GetAxialDirection(direction);
}

FVector HexUtils::GetNeighbor(const FVector& hex, int direction)
{
    return hex + GetCubeDirection(direction);
}

FVector HexUtils::GetEdge(const FVector& hex, int direction)
{
    auto neighbor = HexUtils::GetNeighbor(hex, direction);
    return (neighbor + hex) / 2;
}

FVector HexUtils::GetCornerPosition(const FVector & hex, int direction)
{
    auto angle_deg = 60 * direction + 30;
    auto angle_rad = PI / 180 * angle_deg;
    return FVector(hex.X + AHexagonTile::Size * cos(angle_rad),
                 hex.Y + AHexagonTile::Size * sin(angle_rad), 0);
}

FVector HexUtils::GetCornerCube(int direction)
{
    const float onethird = 1.f / 3.f;
    const float twothird = 2.f / 3.f;

    switch (direction) {
    case 0:
        return FVector(onethird, -twothird, onethird);
    case 5:
        return FVector(twothird, -onethird, -onethird);
    case 4:
        return FVector(onethird, onethird, -twothird);
    case 3:
        return FVector(-onethird, twothird, -onethird);
    case 2:
        return FVector(-twothird, onethird, onethird);
    case 1:
        return FVector(-onethird, -onethird, twothird);
    default:
        // UE_LOG(Error, ELogVerbosity::Error, TEXT("HexUtils::GetCornerAxial unknown direction"));
        return FVector::ZeroVector;
        break;
    }
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