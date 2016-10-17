#include "Catan.h"
#include "PlayerAction.h"

char* PlayerAction_tostring(PlayerAction action)
{
    switch (action) {
    case PlayerAction::Select:
        return "Select";
        break;
    case PlayerAction::PlaceSettlement:
        return "PlaceSettlement";
        break;
    default:
        return "Not Defined";
        break;
    }
}