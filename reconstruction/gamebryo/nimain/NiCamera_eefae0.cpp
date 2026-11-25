// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiCamera: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioneefae0: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xeefae0 NiCamera::Functioneefae0
// CI hash: 0xeefae0 ?Functioneefae0@NiCamera@@QEAAXAEBUFrustumeefae0@@@Z
#include "NiCamera_eefae0.h"

// Guess: Set the camera frustum while enforcing the near-plane bounds.
void NiCamera::Functioneefae0(const Frustumeefae0& frustum)
{
    nearPlane = frustum.nearPlane;
    float requiredNear = frustum.farPlane / maxFarNearRatio;
    if (nearPlane < requiredNear) { nearPlane = requiredNear; }
    if (nearPlane < minNearPlaneDist) { nearPlane = minNearPlaneDist; }
    left = frustum.left;
    right = frustum.right;
    top = frustum.top;
    bottom = frustum.bottom;
    farPlane = frustum.farPlane;
    ortho = frustum.ortho;
}
