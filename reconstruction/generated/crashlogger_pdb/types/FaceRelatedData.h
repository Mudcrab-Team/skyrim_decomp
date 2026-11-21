// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FaceRelatedData; size 0xc8
#pragma once

struct BGSColorForm;
struct BGSTextureSet;
struct BSTArray_RE__BGSColorForm_89b87904;
struct BSTArray_RE__BGSHeadPart_e1306f84_8a657a0d;
struct RE__BSTArray_RE__BGSTextureSet_30cc88f9;
struct RE__BSTArray_RE__TESNPC_deb8e3eb_f3909555;
struct RE__BSTArray_RE__TESRace__FaceRelatedData__TintAsset_f8289196;
struct FaceRelatedData {
    unsigned char availableMorphs_raw[128];
    unsigned int numFlagsSet[4];
    RE__BSTArray_RE__TESRace__FaceRelatedData__TintAsset_f8289196* tintMasks;
    RE__BSTArray_RE__BGSTextureSet_30cc88f9* faceDetailsTextureSets;
    BGSTextureSet* defaultFaceDetailsTextureSet;
    RE__BSTArray_RE__TESNPC_deb8e3eb_f3909555* presetNPCs;
    BSTArray_RE__BGSColorForm_89b87904* availableHairColors;
    BGSColorForm* defaultHairColor;
    BSTArray_RE__BGSHeadPart_e1306f84_8a657a0d* headParts;
};
static_assert(sizeof(FaceRelatedData) == 200, "FaceRelatedData layout differs from the PDB");
