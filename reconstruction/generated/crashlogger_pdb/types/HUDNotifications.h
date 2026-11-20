// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HUDNotifications; size 0x78
#pragma once

#include "BSTArray_RE__HUDNotifications__Notification_abb58e4b.h"
#include "GFxValue_d037b5d2.h"
#include "HUDObject_35c821a3.h"
struct HUDNotifications {
    HUDObject_35c821a3 _base;
    BSTArray_RE__HUDNotifications__Notification_abb58e4b queue;
    GFxValue_d037b5d2 root;
    GFxValue_d037b5d2 objectives;
    unsigned int time;
    float levelPoints;
};
static_assert(sizeof(HUDNotifications) == 120, "HUDNotifications layout differs from the PDB");
