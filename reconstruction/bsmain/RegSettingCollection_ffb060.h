// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// RegSettingCollection: CRASHLOGGER_PDB(59818@2026.10.24)
// RegSettingCollection::CloseHandle_140D5DB00: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
#pragma once

extern "C" __declspec(dllimport) long Func00d9b06c(volatile long* dest, long exchange, long comparand);

namespace f3m_00ab5a70 {
struct Lock;

struct Lock {
    long volatile owner;
    unsigned int depth;
    void Func00409a80(const char* source);
    void Release()
    {
        if (--depth == 0) {
            const long previousOwner = owner;
            Func00d9b06c(&owner, 0, previousOwner);
        }
    }
};

class C
{
public:
    void* unk00;
    int* unk04;
    int* unk08;
    int* unk0c;
    void* unk10;
    unsigned int unk14;
    int unk18;
    bool Func00aa31d0(int a, int b, int c);
    bool Func00aa39f0(int a, int b, int c, Lock* d);
};


extern "C" __declspec(dllimport) long RegCloseKey(struct HKEY__*);
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct RegSettingCollection
{
  public:
    char padding_0_[272];
    HKEY__ *key;
    bool CloseHandle_140D5DB00();
};
}
