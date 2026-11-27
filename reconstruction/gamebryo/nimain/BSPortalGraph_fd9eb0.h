// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// alwaysRenderChildren, NiAVObject: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPortalGraph, BSOcclusionShape, AddOcclusionShape, RemoveOcclusionShape and occlusionShapes: CRASHLOGGER_PDB(59818@2026.10.24)
// ObjectArray, Erase, ShapeItem, OcclusionShapeList and Find: GUESS(low)
#pragma once

#include "OcclusionShapeList.h"

class NiAVObject;
struct ObjectArray {
    NiAVObject** data;
    unsigned char unknown08[8];
    unsigned int size;
    void Erase(unsigned int index, unsigned int count);
};

struct BSPortalGraph {
    void AddOcclusionShape(BSOcclusionShape* shape);
    void RemoveOcclusionShape(BSOcclusionShape* shape);
    void RemoveAlwaysRenderChild(NiAVObject* child);
    unsigned char unknown00[0x10];
    OcclusionShapeList occlusionShapes;
    unsigned char unknown28[0x30];
    ObjectArray alwaysRenderChildren;
};
