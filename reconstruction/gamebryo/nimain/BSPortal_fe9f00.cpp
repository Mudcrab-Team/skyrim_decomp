// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSPortal, CreateClone, BSOcclusionPlane, entranceRoom, exitRoom, portalSharedNode: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCloningProcess, CreateClone: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// 0xfe9f00 BSPortal::CreateClone
// CI hash: 0xfe9f00 ?CreateClone@BSPortal@@UEAAPEAVNiObject@@AEAVNiCloningProcess@@@Z
#include "BSPortal_fe9f00.h"

// The separate BSPortal::Create factory also assigns null after the NiPointer is constructed.
BSPortal::BSPortal()
{
    portalSharedNode = nullptr;
}

// The clone shares both rooms and starts without shared geometry.
NiObject* BSPortal::CreateClone(NiCloningProcess&)
{
    BSPortal* clone = new BSPortal;
    clone->entranceRoom = entranceRoom;
    clone->exitRoom = exitRoom;
    return clone;
}
