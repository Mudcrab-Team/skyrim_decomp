// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSCullingProcess, TestBaseVisibility1, BSMultiBoundShape and NiCullingProcess layout, BSMultiBound::data: CRASHLOGGER_PDB(59818@2026.10.24)
// ShapeMethods, TestPlanes and the partial shape layout: GUESS(low) STANDIN
#pragma once

#include "generated/crashlogger_pdb/types/NiCullingProcess.h"


struct BSMultiBoundShape;
struct ShapeMethods {
    void* preceding[41];
    bool (*TestPlanes)(BSMultiBoundShape*, NiFrustumPlanes&);
};
struct BSMultiBoundShape {
    ShapeMethods* methods;
};
struct BSMultiBound {
    unsigned char unknown00[0x18];
    BSMultiBoundShape* data;
};

struct BSCullingProcess : NiCullingProcess {
    bool TestBaseVisibility1(BSMultiBound& bound);
};
