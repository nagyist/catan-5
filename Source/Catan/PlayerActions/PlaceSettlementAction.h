#pragma once
#include "PlayerActionBase.h"

class APlayerController;
class ASettlement;

class PlaceSettlementAction : public PlayerActionBase {
public:
    PlaceSettlementAction(APlayerController* controller);
    ~PlaceSettlementAction();

    // Inherited via PlayerActionBase
    virtual void OnEnterAction() override;
    virtual void DoAction() override;
    virtual void OnMouseMove() override;
    virtual void OnLeaveAction() override;

private:
    APlayerController* controller_;
    ASettlement* settlement_;
    FCollisionQueryParams hittestparams_;
};

