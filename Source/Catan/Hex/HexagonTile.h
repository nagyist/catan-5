// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ResourceType.h"
#include "../Map/MapPiece.h"
#include "HexagonTile.generated.h"

UCLASS()
class CATAN_API AHexagonTile : public AMapPiece
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
    ResourceType GetResourceType() const;

    void SetDiceRollValue(uint16 roll);
    uint16 GetDiceRollValue() const;

private:
    UMaterial* pBrickMat_;
    UMaterial* pOreMat_;
    UMaterial* pWoolMat_;
    UMaterial* pWheatMat_;
    UMaterial* pWoodMat_;
    UMaterial* pDesertMat_;

    ResourceType resource_;
    uint16 diceroll_;
};
