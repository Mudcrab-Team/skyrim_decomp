// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// BSResourceStreamParser, BSResourceStreamParser::~BSResourceStreamParser: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

namespace f3m_004a5c10 {
struct DebrisData4a4ae0;
struct DebrisNode4a4ae0;

struct DebrisData4a4ae0 {
    unsigned char percentage;
    unsigned char flags;
    const char* modelPath;
};

struct DebrisNode4a4ae0 {
    DebrisData4a4ae0* data;
    DebrisNode4a4ae0* next;
};


class TESForm
{
public:
    virtual ~TESForm();
    unsigned char formType;
    int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
};

class BGSPreloadable {
public:
    virtual ~BGSPreloadable();
};

class BSResourceStreamParser : public TESForm, public BGSPreloadable {
public:
    virtual ~BSResourceStreamParser();
};

}
