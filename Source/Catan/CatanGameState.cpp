// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include <utility>
#include "Map/Settlement.h"
#include "CatanGameState.h"

BoardManager* ACatanGameState::GetBoardManager() const
{
    return this->boardmanager_.get();
}

bool ACatanGameState::PlaceSettlement(ASettlement * settlement)
{
    if (corners_.find(settlement->GetCoordinates()) != corners_.end()) {
        return false;
    }

    corners_.emplace(settlement->GetCoordinates(), settlement);
    return true;
}
