// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// NiNode, NiAVObject, children and flags: CRASHLOGGER_PDB(59818@2026.10.24)
// Cull, capacity, freeIndex and childCount: GUESS(low)
// BSPortalSharedNode, CreateClone, BSPortal, lights and portal: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCloningProcess, CreateClone: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include "NiObject.h"
#include "GeometryArray.h"
#include "PortalHeapObject.h"

class NiCullingProcess;
struct BSPortal;
struct BSLight;

class NiAVObject : public NiObject {
public:
    void Cull(NiCullingProcess& process, int alphaGroupIndex);
    unsigned char unknown10[0xe4];
    unsigned int flags;
    unsigned char unknownF8[0x18];
};
class NiNode : public NiAVObject {
public:
    explicit NiNode(unsigned short children);
    ~NiNode() override;
    unsigned char unknown110[8];
    NiAVObject** children;
    unsigned short capacity;
    unsigned short freeIndex;
    unsigned short childCount;
};
struct BSPortalSharedNode : NiNode {
    explicit BSPortalSharedNode(BSPortal* owner);
    ~BSPortalSharedNode() override;
    NiObject* CreateClone(NiCloningProcess&) override;
    void OnVisible(NiCullingProcess& process, int alphaGroupIndex);
    static void* operator new(std::size_t size) { return PortalHeapObject::operator new(size); }

    GeometryArray<BSLight*> lights;
    BSPortal* portal;
};
static_assert(sizeof(BSPortalSharedNode) == 0x148, "portal shared node layout");
