// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSPortal, CreateClone, BSOcclusionPlane, entranceRoom, exitRoom, portalSharedNode: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCloningProcess, CreateClone: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include "BSOcclusionPlane_fe8d40.h"
#include "BSPortalSharedNode_fe9c20.h"
struct BSMultiBoundRoom;
struct PortalNodeReference {
    PortalNodeReference() : node(nullptr) {}
    ~PortalNodeReference();
    void Reset()
    {
        if (node) {
            BSPortalSharedNode* previous = node;
            node = nullptr;
            // Only the last owner disposes of the object.
            const unsigned count = _InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->_refCount));
            if (!count) {
                previous->DeleteThis();
            }
        }
    }
    BSPortalSharedNode* node;
};
struct BSPortal : BSOcclusionPlane {
    static void* operator new(std::size_t size) { return PortalHeapObject::operator new(size); }
    BSPortal() { portalSharedNode.Reset(); }
    ~BSPortal() override;
    NiObject* CreateClone(NiCloningProcess&) override;
    BSMultiBoundRoom* entranceRoom;
    BSMultiBoundRoom* exitRoom;
    PortalNodeReference portalSharedNode;
};
