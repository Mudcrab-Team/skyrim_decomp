// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xff5c90 BSGeometryListCullingProcess::SubmitCollectedGeometry
#include "BSGeometryListCullingProcess_ff5c90.h"

void BSGeometryListCullingProcess::SubmitCollectedGeometry(BSCullingProcess& submitter, bool flag)
{
    submitter.SubmitCullResults(objectArray, submitter.camera, true, flag);
}
