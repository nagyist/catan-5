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
    static FVector GetCornerPosition(const FVector& hex, int direction);
    static FVector GetCornerCube(int direction);

private:
    HexUtils();
    ~HexUtils();
    static const FVector cubeDirs[];
    static const FVector2D axialDirs[];
};

//const FMatrix2x2 FlatOrientation(3.f / 2.f, sqrt(3.f) / 2.f, 0.f, sqrt(3.f));
const FMatrix2x2 PointOrientation(sqrt(3.f), 0.f, sqrt(3.f) / 2.f, 3.f / 2.f);
const FMatrix2x2 OrientationInverse(PointOrientation.Inverse());