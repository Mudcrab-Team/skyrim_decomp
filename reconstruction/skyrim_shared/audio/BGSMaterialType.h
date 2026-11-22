// Origin: original reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BGSMaterialType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSMaterialType::ClearData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESForm.h"

// BSFixedString, BSFixedString::~BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// value, parent, materialName, materialKind, color, buoyancy, flags, impact,
// MaterialColor, red, green, blue, defaultMaterialColor: GUESS(low); represented material fields and defaults.
class BSFixedString { public: BSFixedString(const char*); ~BSFixedString(); BSFixedString& operator=(const BSFixedString&); const char* value; };
struct MaterialColor { float red, green, blue; };
extern MaterialColor defaultMaterialColor;
class BGSMaterialType : public TESForm {
public:
    void ClearData() override;
    BGSMaterialType* parent;
    BSFixedString materialName;
    std::uint32_t materialKind;
    MaterialColor color;
    float buoyancy;
    std::uint32_t flags;
    void* impact;
};
static_assert(sizeof(BGSMaterialType)==0x50, "material type size");
