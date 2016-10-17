#pragma once
#include "PlayerActionBase.h"

class APlayerController;

class SelectAction : public PlayerActionBase {
public:
    SelectAction(APlayerController* controller);
    ~SelectAction();

    virtual void OnEnterAction() override;
    virtual void OnLeaveAction() override;

    // Inherited via PlayerActionBase
    virtual void DoAction() override;

private:
    APlayerController* controller_;
};

