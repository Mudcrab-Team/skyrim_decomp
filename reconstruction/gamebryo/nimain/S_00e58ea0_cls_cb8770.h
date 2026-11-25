// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// S_00e58ea0_cls: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// S_00e58ea0_cls::Func00e58ea0: GUESS(low); placeholder name
#pragma once

struct S_00e58ea0_Arr;
struct S_00e58ea0_Gen;


struct S_00e58ea0_Gen
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int Func00e587a0();
    int Func00cc0760();
    void InitFloatArray(int a, int b, float c);
};

struct S_00e58ea0_Arr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void InitFloatArray(int a, int b, float c);
    void Func00c7b0f0();
};

struct S_00e58ea0_cls
{
    int unk00;
    int Func00dbbc00();
    void Func00e58a20(S_00e58ea0_Gen* a, S_00e58ea0_Gen* b, S_00e58ea0_Arr* pkOut);
    S_00e58ea0_Gen* Func00e58ea0(S_00e58ea0_Gen* a1, S_00e58ea0_Gen* a2);
};
