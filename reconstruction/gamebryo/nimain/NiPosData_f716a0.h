// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00a3cd40_cls: GUESS(low); placeholder name
// Func00a3cd40_cls::Func00a3cd40: GUESS(low); placeholder name
// NiPosData: GUESS(low); placeholder name
#pragma once

struct NiFloatData;
struct NiStream;
struct TimedAnimationKey;
struct WriteStream;

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

class NiObject
{
  public:
    virtual void LoadBinary(NiStream&);
    unsigned int refCount;
};

class NiFloatData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;
    TimedAnimationKey* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SetColorKeys(TimedAnimationKey*, unsigned int, AnimationKey::KeyType);
    virtual void LoadBinary(NiStream&);
};


typedef bool(* Func00a3cd40_KeyCmp)(void*, void*);
extern Func00a3cd40_KeyCmp Data011f3ae0[];

struct Func00a3cd40_cls : public NiFloatData
{
    bool IsSameAs(NiFloatData* other);
    bool Func00a3cd40(NiFloatData* other);
};

struct NiPosData
{
};
