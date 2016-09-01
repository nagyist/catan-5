// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CatanPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CATAN_API ACatanPlayerController : public APlayerController
{
    GENERATED_BODY()

    virtual void BeginPlay() override;

protected:
    virtual void SetupInputComponent() override;

private:
    void SelectPressed();
    void SelectReleased();
};
