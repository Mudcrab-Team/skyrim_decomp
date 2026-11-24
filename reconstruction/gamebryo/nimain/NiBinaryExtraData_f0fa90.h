// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryExtraData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryExtraData::SaveBinary_140C83D50: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, padding_c_: GUESS(low); placeholder name
#pragma once

namespace fnv_00a7fa20 {
struct FadeNode;
struct NiBinaryStreamStandIn;
struct NiStreamLike;

struct NiExtraData
{
    void Func00a7b2e0();
};

struct NiBinaryStreamStandIn
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(* read)(NiBinaryStreamStandIn* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    unsigned int BinaryRead(void* buffer, unsigned int totalBytes, unsigned int* componentSizes,
                            unsigned int componentCount)
    {
        unsigned int bytesRead = read(this, buffer, totalBytes, componentSizes, componentCount);
        absolutePosition += bytesRead;
        return bytesRead;
    }
    template <class T> unsigned int Read(T* value)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(value, sizeof(T), &size, 1);
    }
    template <class T> unsigned int Read(T* array, unsigned int count)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(array, sizeof(T) * count, &size, 1);
    }
};

class NiStream
{
  public:
    char pad[0x24c];
    NiBinaryStreamStandIn* istr;
};



// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct FadeNode
{
  public:
    char padding_0_[8];
    int unk04;
    char padding_c_[12];
    int (*unk0c)(FadeNode* node, void* arg2, unsigned int arg3, int* arg4, int arg5);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiStreamLike
{
  public:
    char padding_0_[672];
    FadeNode *unk250;
};

struct NiBinaryExtraData
{
    void* unk00;  // vptr
    int unk04;
    void* unk08;
    void* unk0c;         // the payload pointer
    unsigned int unk10;  // the payload size
    void Func00a7b2c0(NiStreamLike* s);
    void SaveBinary_140C83D50(NiStreamLike* s);
};

}
