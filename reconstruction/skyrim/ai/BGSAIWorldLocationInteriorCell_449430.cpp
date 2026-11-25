// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSAIWorldLocationCell.cpp:102
// 0x449430 BGSAIWorldLocationInteriorCell::LoadGame
// Adapted bodies: BGSAIWorldLocationInteriorCell::LoadGame from the sibling source named above
#include "BGSAIWorldLocationInteriorCell_449430.h"

void BGSAIWorldLocationInteriorCell::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    TESObjectCELL* loaded = nullptr;
    a_buffer->LoadFormID(loaded);
    cell = loaded;
    a_buffer->LoadDataEndian(&point, 12, 4);
}
