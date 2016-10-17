#include "Catan.h"
#include "../Map/Settlement.h"
#include "../Map/MapPiece.h"
#include "../Hex/HexUtils.h"
#include "../Hex/Orientation.h"
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
}

void PlaceSettlementAction::OnMouseMove()
{
    // TODO: Refactor to common location
    FVector cursorlocation;
    FVector cursordirection;
    controller_->DeprojectMousePositionToWorld(cursorlocation, cursordirection);
    FVector traceend = cursorlocation + cursordirection * 10000;

    FHitResult hitresult;
    if (controller_->GetWorld()->LineTraceSingleByChannel(hitresult, cursorlocation, traceend, ECC_Camera, this->hittestparams_)) {
        auto mappiece = dynamic_cast<AMapPiece*>(hitresult.Actor.Get());
        auto hexCoords = mappiece->GetCoordinates();
        auto corner = HexUtils::GetCorner(hexCoords, 0);
        auto hexworld = FVector(PointOrientation.TransformVector(HexUtils::AxialCoord(hexCoords)) * 110, 0);
        corner += hexworld;
        settlement_->SetActorLocation(corner);
    }
}

void PlaceSettlementAction::OnLeaveAction()
{
    settlement_->Destroy();
}
