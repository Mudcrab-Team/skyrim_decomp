// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Data; size 0x14
// one of 13 different PDB types sharing this name
#pragma once
struct Data_ebad1aa0 {
    bool editorVisible;
    bool startNetBoneSet;
    unsigned char unk02;
    unsigned char transDelta;
    unsigned char undefined_4[1];
    unsigned char sunDamage;
    unsigned char precipitationBeginFadeIn;
    unsigned char precipitationEndFadeOut;
    unsigned char undefined_8[1];
    unsigned char thunderLightningEndFadeOut;
    unsigned char thunderLightningFrequency;
    unsigned char flags;  // WeatherDataFlag in the PDB is wider than this slot
    unsigned char undefined_c[3];
    unsigned char visualEffectBegin;
    unsigned char undefined_10[1];
    unsigned char windDirection;
    unsigned char windDirectionRange;
    unsigned char unk13;
};
static_assert(sizeof(Data_ebad1aa0) == 20, "Data_ebad1aa0 layout differs from the PDB");
