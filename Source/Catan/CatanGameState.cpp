// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "CatanGameState.h"

BoardManager* ACatanGameState::GetBoardManager() const
{
    return this->boardmanager_.get();
}