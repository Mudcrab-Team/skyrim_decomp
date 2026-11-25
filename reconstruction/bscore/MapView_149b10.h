// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// MapView: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// MapView::ClearAll: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_5_, padding_c_: GUESS(low); placeholder name
// MemoryManager, BSMapBase, ScrapHeapBuffer, IMemoryHeap: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); declaration taken from the sibling decompilation, identity with this function unproven
// IMemoryManagerFile: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); declaration taken from the sibling decompilation, identity with this function unproven
// MemoryHeapStats: GUESS(low) STANDIN; forward declaration, no sibling header declares it
#pragma once

struct MemoryHeapStats;

template <class K, class V> class BSMapBase
{
  public:
    char data[16];
    bool GetAt(K, V&);
    void SetAt(K, V);
};

class ScrapHeapBuffer
{
  public:
    char data[16];
    ScrapHeapBuffer();
    static inline void* operator new(size_t size);
    static inline void operator delete(void* p);
};

class IMemoryManagerFile
{
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int Write(const void* buffer, unsigned int size);
    virtual void vf03();
    virtual void vf04(int aiPos);
};

class IMemoryHeap
{
  public:
    virtual ~IMemoryHeap();
    virtual const char* GetName() = 0;
    virtual void* Allocate(unsigned int size, unsigned int alignment) = 0;
    virtual void Deallocate(void* pointer, unsigned int alignment) = 0;
    virtual bool ContainsBlockImpl(const void* pointer) = 0;
    virtual void CheckHeapIntegrity() = 0;
    virtual void GetHeapStats(MemoryHeapStats* stats, bool full) = 0;
    virtual int OutputBucketInfo(IMemoryManagerFile* file) = 0;
    virtual int OutputBlockInfo(IMemoryManagerFile* file, bool full) = 0;
    virtual unsigned int Size(const void* pointer, unsigned int alignment) = 0;
};

class MemoryManager
{
  public:
    unsigned char layoutPadding0[0x114];
    BSMapBase<unsigned long, ScrapHeapBuffer*> threadScrapHeaps;
    char pad124[5];
    bool m_bPoolAllocationEnabled;  // +0x129
    unsigned char layoutPadding12A[2];
    static MemoryManager& Instance();
    ScrapHeapBuffer* GetGeneralAllocator();
    void CreatePool(unsigned int blockSize, unsigned int poolSize, char* description);
    void* Allocate(unsigned int size);
    void Deallocate(void* pointer);
    void* Reallocate(void* pointer, unsigned int size);
    unsigned int Size(const void* pointer);
    IMemoryHeap* GetHeapForPointer(const void* pointer);
    IMemoryHeap* GetHeapForPhysicalPointer(const void* pointer);
};

extern MemoryManager g_memoryManager;

struct ScrapView;
struct WeightedMapNode;

struct ScrapView
{
    ~ScrapView();
    static inline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

struct WeightedMapNode
{
    WeightedMapNode* unk00;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct MapView
{
  public:
    virtual void vslot_0_();
    virtual void vslot_1_();
    virtual void vslot_2_();
    virtual void vslot_3_();
    virtual void slot4(WeightedMapNode*);
    virtual void vslot_5_();
    virtual void slot6(WeightedMapNode*);
    unsigned int unk04;
    char padding_c_[4];
    WeightedMapNode **unk08;
    unsigned int unk0C;
    ~MapView();
    inline WeightedMapNode* First();
    void Func00a0c850(WeightedMapNode*&, unsigned long&, ScrapView*&);
    void ClearAll();
};
