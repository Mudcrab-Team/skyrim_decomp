// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// bhkPrismaticConstraint, bhkPrismaticConstraint::~bhkPrismaticConstraint: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
#pragma once

#include <stddef.h>

extern char* EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct NiExtraData;
struct NiFixedString;
struct NiNode;
struct RgbaColor;
struct Tile;

struct NiGlobalStringTable
{
    static char* AddString(const char*);
    static long* GetRealBufferStart(char* const& h)
    {
        return ((long*)h) - 2;
    }
    static void DecRefCount(char*& h)
    {
        if (h == EmptyFS)
            return;
        NiAtomicSubtract(GetRealBufferStart(h)[0]);
    }
    static const char* GetString(char* const& h)
    {
        return h;
    }
    static long NiAtomicSubtract(long& v)
    {
        return InterlockedDecrement(&v);
    }
};

class NiFixedString
{
  public:
    NiFixedString(const char* pc)
    {
        if (pc == 0)
            m_kHandle = EmptyFS;
        else
            m_kHandle = NiGlobalStringTable::AddString(pc);
    }
    ~NiFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    operator const char*() const
    {
        return NiGlobalStringTable::GetString(m_kHandle);
    }
    char* m_kHandle;
};

class NiExtraData
{
  public:
    NiExtraData();
    virtual ~NiExtraData();
    void SetName(const NiFixedString& name);
    int unk04;
    int unk08;
};

struct NiNodeChildArray
{
    NiNodeChildArray(int maxSize, int growBy);
    ~NiNodeChildArray();
    void RemoveAll();
    void* vtbl;
    int m_pBase;
    int m_usMaxSize;
    int m_usGrowBy;
};

class NiObjectNET
{
  public:
    virtual ~NiObjectNET();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(NiNode* child, bool firstAvail);
    bool AddExtraData(NiExtraData* extra);
    void DecRefCount();
    void IncRefCount();
};

class NiNode : public NiObjectNET
{
  public:
    NiNode(unsigned short arraySize);
    void UpdateModel();
    static void* operator new(size_t size);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiNode* m_pParentNode;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    NiNodeChildArray m_kChildList;
};

class Tile
{
  public:
    virtual Tile* Destroy(bool doFree);
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalcNode();
    virtual unsigned int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk05(float first, float second);
    virtual Tile* UpdateField(unsigned int valueID, float floatValue, const char* strValue);
    virtual void ClearTextures();
    virtual void* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, const RgbaColor& color);

    char layoutPadding[0x34];
};

struct bhkPrismaticConstraint : NiExtraData
{
    Tile* pTile;
    NiNode* pNode;
    bhkPrismaticConstraint();
    static void* operator new(size_t size);
};

struct Globals
{
};
