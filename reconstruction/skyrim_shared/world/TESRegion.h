// Source exposure: mixed (target listing, public declarations, sibling hint).
// Origin: public declarations and anonymous sibling code.
// TESRegion::Validate: SIBLING(fo4-private@1b765c70, author-permission); adapted region validation.
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegion.cpp:263
// TESRegion, TESRegionDataList, TESRegionPointList, TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations adapted from include/RE/T/TESRegion.h and include/RE/T/TESForm.h.
// Validate, RegionPointNode: GUESS(low); names and signatures remain unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESFile;
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent {
public:
    TESFile** sourceFiles;
    std::uint32_t formFlags, formID;
    std::uint16_t inGameFlags;
    std::uint8_t formType, pad1B;
    std::uint32_t pad1C;
};
class TESRegionDataList { public: bool Validate(); };
class TESRegionPointList { public: bool Validate(bool); };
struct RegionPointNode { TESRegionPointList* item; RegionPointNode* next; };
class TESRegion : public TESForm {
public:
    bool Validate();
    TESRegionDataList* dataList;
    RegionPointNode* pointLists;
};
