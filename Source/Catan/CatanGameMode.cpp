// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include <memory>
#include <chrono>
#include "CatanGameMode.h"
#include "CatanGameState.h"
#include "Hex/HexagonTile.h"
#include "Hex/BoardManager.h"
#include "CatanPlayerController.h"
#include "CatanPawn.h"

ACatanGameMode::ACatanGameMode()
    : Super()
{
    this->PlayerControllerClass = ACatanPlayerController::StaticClass();
    this->DefaultPawnClass = ACatanPawn::StaticClass();
    this->GameStateClass = ACatanGameState::StaticClass();
}

void ACatanGameMode::InitGameState()
{
    AGameMode::InitGameState();
    this->SpawnMap();
}

void ACatanGameMode::SpawnMap() const
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto boardmanager = std::make_unique<BoardManager>(seed, GetGameState<ACatanGameState>());
    boardmanager->BuildMap(GetWorld());
    this->GetGameState<ACatanGameState>()->boardmanager_ = std::move(boardmanager);
}
