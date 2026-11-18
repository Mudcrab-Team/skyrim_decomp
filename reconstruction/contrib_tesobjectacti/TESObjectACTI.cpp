// Code origin: GetWaterType, GetIgnoredBySandbox and IsWater bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x2677d0 TESObjectACTI::GetWaterType
// 0x267690 TESObjectACTI::GetIgnoredBySandbox
// 0x27a690 TESObjectACTI::IsWater
#include "TESObjectACTI.h"
TESWaterForm* TESObjectACTI::GetWaterType() const { return waterForm; }
bool TESObjectACTI::GetIgnoredBySandbox() const { return (flags >> 1) & 1; }
bool TESObjectACTI::IsWater() const { return waterForm != nullptr; }
