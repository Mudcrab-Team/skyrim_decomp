// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// SaveKeyArray: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct A28260Key;
struct NiStream;


class NiStream;

class NiColorSaveHelper {
public:
    float r;
    float g;
    float b;

    void SaveBinary(NiStream& kStream);
};

struct A28260Key {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiColorSaveHelper m_kColor0;
    NiColorSaveHelper m_kColor1;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

void ApplyAnimToTarget(NiStream& kStream, A28260Key* pkKey);

struct Globals
{
};
