// Source exposure: mixed (local pinned-image analysis and declared community hypotheses).
// Code origin: original reconstruction from the contributor-owned image.
// BSCompoundFrustum, AddOcclusionShapeToGroup, BSOcclusionShape, BSOcclusionBox, IsPotentiallyVisible, camera, freeOp, AddOcclusionBox, AddPortal, StartGroupIntersection: CRASHLOGGER_PDB(59818@2026.10.24)
// ShapeMethods, state, first, view: GUESS(low) STANDIN
#pragma once

struct NiCamera;
struct BSOcclusionShape;
struct ShapeMethods {
    void* preceding[37];
    bool (*IsPlane)(BSOcclusionShape*);
};
struct BSOcclusionShape {
    ShapeMethods* methods;
    unsigned char unrecovered08[0x38];
    unsigned int state;
    bool IsPotentiallyVisible(const void* view, const void* position);
};
struct BSOcclusionBox : BSOcclusionShape {
    bool IsPotentiallyVisible(NiCamera* camera, const void* view);
};
struct NiCamera { unsigned char unrecovered00[0xA0]; float position[3]; };
struct BSCompoundFrustum {
    unsigned char unrecovered00[0xB0];
    NiCamera* camera;
    unsigned int freePlane;
    int freeOp;
    void StartGroupIntersection();
    void AddPortal(BSOcclusionShape* plane);
    bool AddOcclusionBox(BSOcclusionBox* box);
    void AddOcclusionShapeToGroup(BSOcclusionShape* shape, const void* view, bool& first);
};
