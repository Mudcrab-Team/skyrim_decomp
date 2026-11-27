// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfed6e0 BSCullingProcess::BSCullingProcess
#include "BSCullingProcess_fed6e0.h"

BSCullingProcess::BSCullingProcess(NiVisibleArray* visibleSet)
    : NiCullingProcess(visibleSet),
      portalGraphEntry(nullptr),
      compoundFrustum(nullptr),
      cullModeStackIndex(0),
      recurseToGeometry(true),
      isGroupingAlphas(false),
      alphaGroupIndex(-1),
      alphaGroupStopIndex(0)
{
}
