#include "Catan.h"
#include "../Map/Settlement.h"
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
        settlement_->SetActorLocation(hitresult.ImpactPoint);
    }
}

void PlaceSettlementAction::OnLeaveAction()
{
    settlement_->Destroy();
}
