// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>
#include "GameFramework/PlayerController.h"
#include "PlayerAction.h"
#include "PlayerActions/PlayerActionBase.h"
#include "CatanPlayerController.generated.h"

class PlayerActionBase;

UCLASS()
class CATAN_API ACatanPlayerController : public APlayerController
{
    GENERATED_BODY()
    ACatanPlayerController();
    ~ACatanPlayerController();

    virtual void BeginPlay() override;

protected:
    virtual void SetupInputComponent() override;

private:
    void DoAction();
    void ToggleAction();
    void MouseMoved(float amt);

    PlayerAction current_action_;
    std::unordered_map<PlayerAction, PlayerActionBase*> actions_;
};
