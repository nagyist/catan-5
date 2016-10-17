// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class CATAN_API HexUtils
{
public:
    static FVector2D AxialCoord(const FVector& cube);
    static FVector CubeCoord(const FVector2D& axial);
    static FVector GetCubeDirection(int direction);
    static FVector2D GetAxialDirection(int direction);
    static FVector2D GetNeighbor(const FVector2D& hex, int direction);
    static FVector GetNeighbor(const FVector& hex, int direction);
    static FVector GetEdge(const FVector& hex, int direction);
    static FVector GetCorner(const FVector& hex, int direction);

private:
    HexUtils();
    ~HexUtils();
    static const FVector cubeDirs[];
    static const FVector2D axialDirs[];
};
