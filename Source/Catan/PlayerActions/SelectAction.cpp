#include "Catan.h"
#include "SelectAction.h"
#include "../hex/HexagonTile.h"

SelectAction::SelectAction(APlayerController* controller)
{
    this->controller_ = controller;
}

SelectAction::~SelectAction()
{}

void SelectAction::OnEnterAction()
{}

void SelectAction::OnLeaveAction()
{}

void SelectAction::DoAction()
{
    FVector cursorlocation;
    FVector cursordirection;
    controller_->DeprojectMousePositionToWorld(cursorlocation, cursordirection);
    FVector traceend = cursorlocation + cursordirection * 10000;

    FHitResult hitresult;
    if (controller_->GetWorld()->LineTraceSingleByChannel(hitresult, cursorlocation, traceend, ECC_Camera)) {
        UE_LOG(LogTemp, Display, TEXT("Selected %s %s"), *hitresult.Actor->GetName(), *hitresult.ImpactPoint.ToString());
        auto mappiece = dynamic_cast<AHexagonTile*>(hitresult.Actor.Get());
        if (mappiece != nullptr) {
            mappiece->SetResourceType(ResourceType::Desert);
        }
    }
}
