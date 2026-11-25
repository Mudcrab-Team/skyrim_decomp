// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSPortalSharedNode, lights, portal, NiNode flags and BSTArrayHeapAllocator: CRASHLOGGER_PDB(59818@2026.10.24)
// LightArray, ArrayCount and the flag meaning: GUESS(low) STANDIN
#pragma once

struct NiNode {
    explicit NiNode(unsigned short children);
    virtual ~NiNode();
    unsigned char unknown08[0xEC];
    unsigned int flags;
    unsigned char unknownF8[0x30];
};
struct BSTArrayHeapAllocator {
    BSTArrayHeapAllocator();
    ~BSTArrayHeapAllocator();
    void* data;
    unsigned int capacity;
};
struct ArrayCount {
    ArrayCount();
    unsigned int size;
};
struct LightArray : BSTArrayHeapAllocator, ArrayCount {
    LightArray() {}
};
struct BSPortal;
struct BSPortalSharedNode : NiNode {
    explicit BSPortalSharedNode(BSPortal* owner);
    ~BSPortalSharedNode() override;
    LightArray lights;
    BSPortal* portal;
};
