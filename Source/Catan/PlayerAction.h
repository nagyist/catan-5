#pragma once

enum PlayerAction {
    UNKNOWN = -1,
    Select,
    PlaceSettlement,
    NUM_ACTIONS
};

char* PlayerAction_tostring(PlayerAction action);