#pragma once
class PlayerActionBase {
public:
    virtual void OnEnterAction() {}
    virtual void DoAction() = 0;
    virtual void OnMouseMove() {}
    virtual void OnLeaveAction() {}
};

