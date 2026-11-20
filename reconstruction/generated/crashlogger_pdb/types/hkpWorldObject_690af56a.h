// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldObject; size 0xd0
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_RE__hkpProperty_2a5fa8bd.h"
#include "hkMultiThreadCheck_64f82694.h"
#include "hkReferencedObject.h"
#include "hkStringPtr_33d8e88b.h"
#include "hkpLinkedCollidable_99608242.h"
struct hkpWorld;
struct hkpWorldObject_690af56a {
    hkReferencedObject _base;
    hkpWorld* world;
    unsigned long long userData;
    hkpLinkedCollidable_99608242 collidable;
    hkMultiThreadCheck_64f82694 multiThreadCheck;
    unsigned int padAC;
    hkStringPtr_33d8e88b name;
    hkArray_RE__hkpProperty_2a5fa8bd properties;
    void* treeData;
};
static_assert(sizeof(hkpWorldObject_690af56a) == 208, "hkpWorldObject_690af56a layout differs from the PDB");
