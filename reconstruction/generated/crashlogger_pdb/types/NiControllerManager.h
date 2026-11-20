// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiControllerManager; size 0xc8
#pragma once

#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_03e03c3f.h"
#include "NiPointer_RE__NiAVObjectPalette_7b21fc8f.h"
#include "NiTObjectArray_RE__NiPointer_RE__NiControllerSequence_5055756c.h"
#include "NiTObjectSet_RE__NiPointer_RE__NiControllerSequence_066b0d0e.h"
#include "NiTPrimitiveSet_RE__NiControllerSequence_5c7b64d3.h"
#include "NiTimeController_82cd7662.h"
struct BSAnimNoteListener;
struct NiControllerManager {
    NiTimeController_82cd7662 _base;
    NiTObjectArray_RE__NiPointer_RE__NiControllerSequence_5055756c sequenceArray;
    NiTPrimitiveSet_RE__NiControllerSequence_5c7b64d3 activeSequences;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_03e03c3f stringMap;
    BSAnimNoteListener* listener;
    bool cumulative;
    unsigned char padA9;
    unsigned short padAA;
    unsigned int padAC;
    NiTObjectSet_RE__NiPointer_RE__NiControllerSequence_066b0d0e tempBlendSeqs;
    NiPointer_RE__NiAVObjectPalette_7b21fc8f objectPalette;
};
static_assert(sizeof(NiControllerManager) == 200, "NiControllerManager layout differs from the PDB");
