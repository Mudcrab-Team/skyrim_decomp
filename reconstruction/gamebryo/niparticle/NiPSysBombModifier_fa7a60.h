// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// LoadEnum: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// NiPSysBombModifier: GUESS(low); placeholder name
#pragma once

class AnimationKey
{
  public:
    enum KeyType
    {
        NiAnimationKey__KeyType_NOINTERP = 0,
        NiAnimationKey__KeyType_LINKEY = 1,
        NiAnimationKey__KeyType_BEZKEY = 2,
        NiAnimationKey__KeyType_TCBKEY = 3,
        NiAnimationKey__KeyType_EULERKEY = 4,
        NiAnimationKey__KeyType_STEPKEY = 5,
        NiAnimationKey__KeyType_NUMKEYTYPES = 6
    };
};

struct NiStream;
struct StreamBinView_cf;
struct TimedAnimationKey;
struct WriteStream;

struct WriteStream
{
    void* data00;
    unsigned int position04;
    unsigned int unk08;
    unsigned int(* write0c)(WriteStream*, const void*, unsigned int, unsigned int*, int);
    inline void Write(const void* data)
    {
        unsigned int size = 4;
        position04 += write0c(this, data, 4, &size, 1);
    }
};

struct NiStream
{
    WriteStream* GetWriter()
    {
        return *reinterpret_cast<WriteStream**>((char*)this + 0x250);
    }
};


typedef TimedAnimationKey*(* CreateFn_cf)(NiStream&, unsigned int);
typedef void(* FillFn_cf)(TimedAnimationKey*, unsigned int, unsigned char);
extern CreateFn_cf Data011f3db0[];
extern FillFn_cf Data011f3780[];

struct StreamStand_cf
{
    void* vtable;
    unsigned int refCount;
    void LoadStream(NiStream& stream);
};

struct KeyOwnerStand_cf
{
    void* vtable;
    unsigned int refCount;
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SetKeyData(TimedAnimationKey* keys, unsigned int numKeys, int type);
};

struct StreamBinView_cf
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(* read)(StreamBinView_cf* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct NiPSysBombModifier
{
};
