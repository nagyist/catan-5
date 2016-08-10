// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CatanGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CATAN_API ACatanGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
    void InitGameState() override;

private:
    void SpawnMap() const;
};
