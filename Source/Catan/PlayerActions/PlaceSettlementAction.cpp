#include "Catan.h"
#include <UnrealMathUtility.h>
#include "../Map/Settlement.h"
#include "../Map/MapPiece.h"
#include "../Hex/HexagonTile.h"
#include "../Hex/HexUtils.h"
#include "../CatanGameState.h"
#include "PlaceSettlementAction.h"


PlaceSettlementAction::PlaceSettlementAction(APlayerController* controller)
{
    this->controller_ = controller;
}

PlaceSettlementAction::~PlaceSettlementAction()
{}

void PlaceSettlementAction::OnEnterAction()
{
    FActorSpawnParameters spawn_parameters;
    settlement_ = controller_->GetWorld()->SpawnActor<ASettlement>(ASettlement::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
    this->hittestparams_.AddIgnoredActor(settlement_);
}

void PlaceSettlementAction::DoAction()
{
    auto gamestate = controller_->GetWorld()->GetGameState<ACatanGameState>();
    if (gamestate->PlaceSettlement(settlement_)) {
        settlement_ = controller_->GetWorld()->SpawnActor<ASettlement>(ASettlement::StaticClass(), settlement_->GetActorLocation(), FRotator::ZeroRotator);
        this->hittestparams_.ClearIgnoredComponents();
        this->hittestparams_.AddIgnoredActor(settlement_);
    }
}

void PlaceSettlementAction::OnMouseMove()
{
    // TODO: Refactor to common location
    const FPlane groundplane(FVector(0.f, 0.f, groundplaneheight_), FVector(0.f, 0.f, 1.f));
    FVector cursorlocation;
    FVector cursordirection;
    controller_->DeprojectMousePositionToWorld(cursorlocation, cursordirection);
    FVector traceend = cursorlocation + cursordirection * 10000;
    auto intersection = FMath::LinePlaneIntersection(cursorlocation, traceend, groundplane);
    auto gamestate = controller_->GetWorld()->GetGameState<ACatanGameState>();
    auto cornercubecoords = gamestate->GetBoardManager()->ClosestCorner(intersection);
    auto cornerworldposition = FVector(PointOrientation.TransformVector(HexUtils::AxialCoord(cornercubecoords)), 0) * AHexagonTile::Size;

    // Apply a bit of "stickiness" to the current corner. Only switch corners if the new one is at least 50% better than the old one
    auto olddist = (closestcorner_ - intersection).SizeSquared();
    auto newdist = (cornerworldposition - intersection).SizeSquared();
    if (newdist < (olddist * 0.5f)) {
        UE_LOG(LogTemp, Verbose, TEXT("New Corner (Old Dist: %d) (New Dist: %d) %s"), olddist, newdist, *cornerworldposition.ToString());
        closestcorner_ = cornerworldposition;
        settlement_->SetActorLocation(cornerworldposition);
        settlement_->SetCoordinates(cornercubecoords);
    }
}

void PlaceSettlementAction::OnLeaveAction()
{
    settlement_->Destroy();
}
