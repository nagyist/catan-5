// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include "GameFramework/GameState.h"
#include "Hex/BoardManager.h"
#include "CatanGameState.generated.h"

class ACatanGameMode;

UCLASS()
class CATAN_API ACatanGameState : public AGameState
{
    GENERATED_BODY()

    friend class ACatanGameMode;

public:
    BoardManager* GetBoardManager() const;

protected:
    std::unique_ptr<BoardManager> boardmanager_;
};
