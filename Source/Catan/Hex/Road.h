// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Road.generated.h"

UCLASS()
class CATAN_API ARoad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoad();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    void SetEdge(UStaticMeshComponent* edge);

private:
    UStaticMeshComponent* pEdge1 = nullptr;
    UStaticMeshComponent* pEdge2 = nullptr;
	
};
