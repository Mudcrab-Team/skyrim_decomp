// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RaceMenuSlider; size 0x138
#pragma once
struct RaceMenuSlider {
    float min;
    float max;
    float value;
    float interval;
    unsigned int filterFlag;
    unsigned int type;
    char* name;
    unsigned char callback[260];
    unsigned int index;
    unsigned int id;
    unsigned int unk12C;
    float currentValue;
    unsigned char unk134;
    unsigned char undefined_135[3];
};
static_assert(sizeof(RaceMenuSlider) == 312, "RaceMenuSlider layout differs from the PDB");
