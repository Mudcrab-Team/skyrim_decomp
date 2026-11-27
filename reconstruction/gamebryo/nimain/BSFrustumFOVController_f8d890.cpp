// Source exposure: mixed (local pinned-image analysis and declared community hypotheses).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xf8d890 BSFrustumFOVController::GetCameraFOV
// CI hash: 0xf8d890 ?GetCameraFOV@BSFrustumFOVController@@QEAAXAEAM@Z
#include "BSFrustumFOVController_f8d890.h"

#include <math.h>
void BSFrustumFOVController::GetCameraFOV(float& value)
{
    value = 2.0f * atanf(target->right);
}
