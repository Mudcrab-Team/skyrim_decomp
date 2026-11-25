// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x15868e0 BSParabolicCullingProcess::BSParabolicCullingProcess
#include "BSParabolicCullingProcess_15868e0.h"

BSParabolicCullingProcess::BSParabolicCullingProcess()
    : backHemisphereAccumulator(), equatorialPlane(),
      lightPosition{defaultPosition.x, defaultPosition.y, defaultPosition.z},
      lightRadius(0.0f), lightCamera(nullptr)
{
}
