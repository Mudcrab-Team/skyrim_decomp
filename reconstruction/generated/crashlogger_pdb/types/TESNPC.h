// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESNPC; size 0x268
#pragma once

#include "BGSOverridePackCollection.h"
#include "BSFixedString_char_83b572b4.h"
#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "Color_aa361e09.h"
#include "Skills.h"
#include "Sounds.h"
#include "TESActorBase_199eb558.h"
#include "TESRaceForm.h"
struct BGSHeadPart_a86c4018;
struct BGSListForm;
struct BGSOutfit;
struct FaceData;
struct HeadRelatedData;
struct RE__BSTArray_RE__BGSRelationship_22ae2bea;
struct RE__BSTArray_RE__TESNPC__Layer_38b9193d;
struct TESClass_b3a94e24;
struct TESCombatStyle_cff5b770;
struct TESFaction_fe5903c5;
struct TESObjectARMO_295db33a;
struct TESRace;
struct TESNPC {
    TESActorBase_199eb558 _base;
    TESRaceForm _base_TESRaceForm;
    BGSOverridePackCollection _base_BGSOverridePackCollection;
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base_BSTEventSink_RE_MenuOpenCloseEvent_;
    Skills playerSkills;
    TESClass_b3a94e24* npcClass;
    HeadRelatedData* headRelatedData;
    BGSListForm* giftFilter;
    TESCombatStyle_cff5b770* combatStyle;
    unsigned int fileOffset;
    unsigned int pad1E4;
    TESRace* originalRace;
    TESNPC* faceNPC;
    float height;
    float weight;
    Sounds sounds;
    BSFixedString_char_83b572b4 shortName;
    TESObjectARMO_295db33a* farSkin;
    BGSOutfit* defaultOutfit;
    BGSOutfit* sleepOutfit;
    BGSListForm* defaultPackList;
    TESFaction_fe5903c5* crimeFaction;
    BGSHeadPart_a86c4018** headParts;
    unsigned char numHeadParts;
    unsigned char unk241;
    unsigned char unk242;
    unsigned char unk243;
    unsigned char unk244;
    unsigned char soundLevel;  // SOUND_LEVEL in the PDB is wider than this slot
    Color_aa361e09 bodyTintColor;
    unsigned short pad24A;
    unsigned int pad24C;
    RE__BSTArray_RE__BGSRelationship_22ae2bea* relationships;
    FaceData* faceData;
    RE__BSTArray_RE__TESNPC__Layer_38b9193d* tintLayers;
};
static_assert(sizeof(TESNPC) == 616, "TESNPC layout differs from the PDB");
