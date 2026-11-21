// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MapMenuMarker; size 0x38
#pragma once

struct TESForm;
struct TESFullName;
struct MapMenuMarker {
    TESFullName* fullName;
    unsigned int ref;
    unsigned int pad0C;
    unsigned char* customMarker;
    unsigned int type;
    unsigned int door;
    int index;
    unsigned int pad24;
    TESForm* form;
    unsigned char unk30;
    unsigned char pad31;
    unsigned short pad32;
    unsigned int pad34;
};
static_assert(sizeof(MapMenuMarker) == 56, "MapMenuMarker layout differs from the PDB");
