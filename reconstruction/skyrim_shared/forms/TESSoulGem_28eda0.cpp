// Source exposure: mixed; binary-analysis and permitted declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: adapted destructor from fo4-private@1b765c70; inferred layout
// Adapted bodies: TESSoulGem::~TESSoulGem
// TESSoulGem::~TESSoulGem: SIBLING(fo4-private@1b765c70, author-permission)
// TESSoulGem: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~TESSoulGem: GUESS(low); provisional member name
// TESSoulGem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x28eda0 TESSoulGem::~TESSoulGem
// CI hash: 0x28eda0 ??1TESSoulGem@@UEAA@XZ
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESSoulGem.cpp:43
#include "TESSoulGem_28eda0.h"

// Guess: Clear the soul-gem data before destruction of the misc-item bases.
 TESSoulGem::~TESSoulGem()
{
    ClearData();
}
