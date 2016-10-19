// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include <unordered_map>
#include "GameFramework/GameState.h"
#include "Hex/BoardManager.h"
#include "CatanGameState.generated.h"

class ACatanGameMode;
class AMapPiece;
class AHexagonTile;
class ARoad;
class ASettlement;

UCLASS()
class CATAN_API ACatanGameState : public AGameState
{
    GENERATED_BODY()
    friend class ACatanGameMode;
    friend class BoardManager;
private:
    struct FVectorHash {
        std::size_t operator()(const FVector& v) const
        {
            std::size_t result = std::hash<float>()(v.X);
            result = (result * 397) ^ std::hash<float>()(v.Y);
            result = (result * 397) ^ std::hash<float>()(v.Z);
            return result;
        }
    };

    struct FVectorEqual {
        bool operator()(const FVector& lhs, const FVector& rhs) const
        {
            return lhs.Equals(rhs);
        }
    };

public:
    BoardManager* GetBoardManager() const;
    bool PlaceSettlement(ASettlement* settlement);

protected:
    std::unique_ptr<BoardManager> boardmanager_;
    std::unordered_map<FVector, AMapPiece*, FVectorHash, FVectorEqual> corners_;
    std::unordered_map<FVector, AHexagonTile*, FVectorHash, FVectorEqual> tiles_;
    std::unordered_map<FVector, ARoad*, FVectorHash, FVectorEqual> roads_;
};
