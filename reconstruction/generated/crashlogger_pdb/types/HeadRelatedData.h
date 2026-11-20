// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeadRelatedData; size 0x10
#pragma once

struct BGSColorForm;
struct BGSTextureSet;
struct HeadRelatedData {
    BGSColorForm* hairColor;
    BGSTextureSet* faceDetails;
};
static_assert(sizeof(HeadRelatedData) == 16, "HeadRelatedData layout differs from the PDB");
