// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class CATAN_API HexUtils
{
public:
    static FVector2D AxialCoord(FVector cube);
    static FVector CubeCoord(FVector2D axial);
    static FVector GetCubeDirection(int direction);
    static FVector2D GetAxialDirection(int direction);
    static FVector2D GetNeighbor(FVector2D hex, int direction);
    static FVector GetNeighbor(FVector hex, int direction);

private:
    HexUtils();
    ~HexUtils();
    static const FVector cubeDirs[];
    static const FVector2D axialDirs[];
};
