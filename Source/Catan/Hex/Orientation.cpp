// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "Orientation.h"

Orientation::Orientation(float m00, float m01, float m10, float m11)
    : orient_mat(new FMatrix2x2(m00, m01, m10, m11))
{
}

Orientation::~Orientation()
{
}
