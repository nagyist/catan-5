// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MapPiece.generated.h"

UCLASS()
class CATAN_API AMapPiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapPiece();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void SetCoordinates(const FVector& cubeCoordinates);
    FVector GetCoordinates() const;

private:
    FVector cubeCoordinates_;
};
