// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// Compare: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataUseItem.cpp:40; adapted comparison.
// TESPackageData and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted declarations.
// TESUseItemPackageData: GUESS(low); qualified-name hint, target type name unverified.
// Pointer, referent and Compare semantics: GUESS(low); signatures unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a14c0 TESUseItemPackageData::Compare
#include "TESUseItemPackageData.h"
bool TESUseItemPackageData::Compare(TESPackageData* src) { auto* p = dynamic_cast<TESUseItemPackageData*>(src); if (!p) return true; if (searchLocation) { if (searchLocation->Compare(p->searchLocation)) return true; } else if (p->searchLocation) return true; return false; }
