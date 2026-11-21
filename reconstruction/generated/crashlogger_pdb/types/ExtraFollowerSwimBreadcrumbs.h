// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraFollowerSwimBreadcrumbs; size 0x38
#pragma once

#include "BREADCRUMB_STATE.h"
#include "BSExtraData_4ca6af76.h"
#include "BSSimpleList_RE__ExtraFollowerSwimBreadcrumb_55f456d6.h"
#include "NiPoint3.h"
struct ExtraFollowerSwimBreadcrumbs {
    BSExtraData_4ca6af76 _base;
    BREADCRUMB_STATE leaderState;
    NiPoint3 leaderLocation;
    unsigned int leaderNavMeshID;
    unsigned int pad24;
    BSSimpleList_RE__ExtraFollowerSwimBreadcrumb_55f456d6 crumbs;
};
static_assert(sizeof(ExtraFollowerSwimBreadcrumbs) == 56, "ExtraFollowerSwimBreadcrumbs layout differs from the PDB");
