// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraEditorRefMoveDataStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraEditorRefMoveData.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x18f220 DeletingLeaf18f220::~DeletingLeaf18f220
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraEditorRefMoveDataStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraEditorRefMoveDataStorageLayout::~ExtraEditorRefMoveDataStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraEditorRefMoveDataStorageLayout) == 56, "independently observed allocation size");
static ResearchLayouts::ExtraEditorRefMoveDataStorageLayout object;
