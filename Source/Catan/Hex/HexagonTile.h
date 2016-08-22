// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ResourceType.h"
#include "HexagonTile.generated.h"

#define k_HalfSqrt3 0.866025404

UCLASS()
class CATAN_API AHexagonTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexagonTile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    static const float Border;
    static const float Size;

    void SetResourceType(ResourceType type);

    void SetCoordinates(const FVector& cubeCoordinates);
    FVector GetCoordinates() const;

private:
    FVector cubeCoordinates_;
    UMaterial* pBrickMat_;
    UMaterial* pOreMat_;
    UMaterial* pWoolMat_;
    UMaterial* pWheatMat_;
    UMaterial* pWoodMat_;
    UMaterial* pDesertMat_;
};
