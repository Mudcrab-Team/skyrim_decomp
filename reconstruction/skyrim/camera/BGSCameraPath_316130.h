// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSCameraPath, BGSCameraPath::conditions, BGSCameraPath::shots, BGSCameraPath::prevPath, TESForm::formFlags, TESCondition, BGSCameraShot: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSCameraPath::ClearData, TESCondition::Clear: CRASHLOGGER_PDB(59818@2026.10.24)
// ShotNode, ShotList, TearDown, RemoveChildPath, TestBit, g_updateCameraPathLinks, unknown38: GUESS(low)
// Adapted bodies: BGSCameraPath::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgscamerapath.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (TestBit similarity).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgscamerapath.cpp:32
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class BGSCameraShot;

struct TESCondition
{
    void Clear();
    void* head;
};

struct ShotNode
{
    ~ShotNode() { TearDown(false, false); }
    void TearDown(bool releaseItems, bool releaseTail);

    BGSCameraShot* item;
    ShotNode* next;
};

struct ShotList
{
    void RemoveAll()
    {
        auto* node = next;
        while (node)
        {
            auto& link = node->next;
            node = link;
            link = nullptr;
            delete next;
            next = node;
        }
        item = nullptr;
    }

    BGSCameraShot* item;
    ShotNode* next;
};

extern __declspec(thread) bool g_updateCameraPathLinks;

class BGSCameraPath : public TESForm
{
public:
    void ClearData() override;
    void RemoveChildPath(BGSCameraPath* child);

    TESCondition conditions;
    ShotList shots;
    std::uint8_t unknown38[0x10];
    BGSCameraPath* prevPath;
};
