// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <memory>

/**
 * 
 */
class CATAN_API Orientation
{
public:
	Orientation(float m00, float m01, float m10, float m11);
	~Orientation();

    std::unique_ptr<FMatrix2x2> orient_mat;
};

//const FMatrix2x2 FlatOrientation(3.f / 2.f, 0.f, sqrt(3.f) / 2.f, sqrt(3.f));
//const FMatrix2x2 PointOrientation(sqrt(3.f), sqrt(3.f) / 2.f, 0.f, 3.f / 2.f);
const FMatrix2x2 FlatOrientation(3.f / 2.f, sqrt(3.f) / 2.f, 0.f, sqrt(3.f));
const FMatrix2x2 PointOrientation(sqrt(3.f), 0.f, sqrt(3.f) / 2.f, 3.f / 2.f);