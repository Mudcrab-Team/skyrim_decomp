// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// TESFurniture::ClearData: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESFurniture.cpp:74
// TESFurniture, TESObjectACTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESObjectACTI.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h and public component headers.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x26e130 TESFurniture::ClearData
// 0x26e680 TESFurniture::CanSit
// 0x26e6a0 TESFurniture::CanSleep
// 0x26e6c0 TESFurniture::HasSit28
// 0x26e6e0 TESFurniture::MustExitToTalk
// 0x26e700 TESFurniture::CanLean
// TESFurniture::CanSit, TESFurniture::CanSleep, TESFurniture::HasSit28, TESFurniture::MustExitToTalk, TESFurniture::CanLean: GUESS(low)
#include "TESFurniture.h"
void TESFurniture::ClearData() { TESObjectACTI::ClearData(); entryPointDataArray.Clear(); }

bool TESFurniture::CanSit() const { return (furnFlags & kCanSit) > 0; }
bool TESFurniture::CanSleep() const { return (furnFlags & kCanSleep) > 0; }
bool TESFurniture::HasSit28() const { return (furnFlags & kSit28) > 0; }
bool TESFurniture::MustExitToTalk() const { return (furnFlags & kMustExitToTalk) > 0; }
bool TESFurniture::CanLean() const { return (furnFlags & kCanLean) > 0; }
