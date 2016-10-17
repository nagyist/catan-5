// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "PlayerActions/SelectAction.h"
#include "PlayerActions/PlaceSettlementAction.h"
#include "CatanPlayerController.h"

ACatanPlayerController::ACatanPlayerController()
{
    this->actions_.emplace(PlayerAction::Select, new SelectAction(this));
    this->actions_.emplace(PlayerAction::PlaceSettlement, new PlaceSettlementAction(this));
}

ACatanPlayerController::~ACatanPlayerController()
{
    for (auto& action : this->actions_) {
        delete action.second;
    }
}

void ACatanPlayerController::BeginPlay()
{
    Super::BeginPlay();

    bShowMouseCursor = true;
    bEnableClickEvents = true;
}

void ACatanPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    
    InputComponent->BindAction(TEXT("SelectAction"),
        IE_Pressed,
        this,
        &ACatanPlayerController::DoAction);

    InputComponent->BindAction(TEXT("ChangeAction"),
        IE_Pressed,
        this,
        &ACatanPlayerController::ToggleAction);

    InputComponent->BindAxis(TEXT("MouseMove"), this, &ACatanPlayerController::MouseMoved);
}

void ACatanPlayerController::DoAction()
{
    auto action = this->actions_.find(this->current_action_);
    if (action != this->actions_.end()) {
        action->second->DoAction();
    }
}

void ACatanPlayerController::ToggleAction()
{
    auto action = this->actions_.find(this->current_action_);
    if (action != this->actions_.end()) {
        action->second->OnLeaveAction();
    }
    this->current_action_ = static_cast<PlayerAction>((static_cast<int>(this->current_action_) + 1) % PlayerAction::NUM_ACTIONS);
    action = this->actions_.find(this->current_action_);
    if (action != this->actions_.end()) {
        action->second->OnEnterAction();
    }
    GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, PlayerAction_tostring(this->current_action_));
}

void ACatanPlayerController::MouseMoved(float amt)
{
    auto action = this->actions_.find(this->current_action_);
    if (action != this->actions_.end()) {
        action->second->OnMouseMove();
    }
}
