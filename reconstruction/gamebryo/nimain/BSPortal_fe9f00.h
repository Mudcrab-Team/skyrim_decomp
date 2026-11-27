// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: NiPointer::operator= follows the project reconstruction in NiObjectNET.h.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSPortal, CreateClone, BSOcclusionPlane, entranceRoom, exitRoom, portalSharedNode: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer, _ptr: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCloningProcess, CreateClone: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include "BSOcclusionPlane_fe8d40.h"
#include "BSPortalSharedNode_fe9c20.h"

struct BSMultiBoundRoom;

template <class T>
class NiPointer {
public:
    ~NiPointer();

    NiPointer& operator=(T* node)
    {
        T* previous = _ptr;
        if (node != previous) {
            if (node) {
                // The reference count is shared between owners.
                _InterlockedIncrement(reinterpret_cast<volatile long*>(&node->_refCount));
            }
            _ptr = node;
            // The last owner disposes of the old node.
            if (previous && _InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->_refCount)) == 0) {
                previous->DeleteThis();
            }
        }
        return *this;
    }

private:
    T* _ptr = nullptr;
};

struct BSPortal : BSOcclusionPlane {
    static void* operator new(std::size_t size) { return PortalHeapObject::operator new(size); }
    BSPortal();
    ~BSPortal() override;
    NiObject* CreateClone(NiCloningProcess&) override;
    BSMultiBoundRoom* entranceRoom;
    BSMultiBoundRoom* exitRoom;
    NiPointer<BSPortalSharedNode> portalSharedNode;
};
