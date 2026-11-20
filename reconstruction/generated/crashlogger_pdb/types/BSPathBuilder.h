// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathBuilder; size 0x28
#pragma once

#include "BSTSmartPointer_RE__BSPathingRequest_c5297c63.h"
#include "BSTSmartPointer_RE__BSPathingSolution_e2b16ca6.h"
#include "IPathBuilder.h"
struct ScrapHeap_aea37981;
struct BSPathBuilder {
    IPathBuilder _base;
    BSTSmartPointer_RE__BSPathingRequest_c5297c63 request;
    BSTSmartPointer_RE__BSPathingSolution_e2b16ca6 solution;
    ScrapHeap_aea37981* threadScrap;
    bool flag20;
    unsigned char pad21[7];
};
static_assert(sizeof(BSPathBuilder) == 40, "BSPathBuilder layout differs from the PDB");
