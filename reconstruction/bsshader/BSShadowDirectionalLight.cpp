// Source exposure: mixed (community headers; the pinned image listing).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original bodies written from the local listing; declarations from the pinned community headers.
// Adapted bodies: none
// 0x1581e30 ShadowArray::~ShadowArray
// 0x157ed10 BSShadowDirectionalLight::GetPassExtraParam
// 0x1581730 BSShadowDirectionalLight::UpdateSunDirectionBlend
#include "BSShadowDirectionalLight.h"

// Engine data read by UpdateSunDirectionBlend.
// bDisableShadowJumps, fSunShadowUpdateTime, g_realDeltaTime, g_sunDirectionCosThreshold: GUESS(low)
extern bool bDisableShadowJumps;
extern float fSunShadowUpdateTime;
extern float g_realDeltaTime;
extern float g_sunDirectionCosThreshold;

void BSShadowDirectionalLight::UpdateSunDirectionBlend(NiPoint3* a_direction, std::int32_t a_previousCameraMoved)
{
    if (!(blendTimer < 1.0f)) {
        if (cameraMoved == 1) {
            fromDirection = targetDirection;
            targetDirection = *a_direction;
            if (a_previousCameraMoved == 0) {
                blendTimer = 0.0f;
            }
        } else if (!bDisableShadowJumps) {
            float d = targetDirection.x * a_direction->x + targetDirection.y * a_direction->y + targetDirection.z * a_direction->z;
            float c = g_sunDirectionCosThreshold;
            if (!(d >= c)) {
                if (!(d >= 1.0f - (1.0f - c) * 2.0f)) {
                    targetDirection = *a_direction;
                    fromDirection = targetDirection;
                    blendTimer = 1.0f;
                } else {
                    fromDirection = targetDirection;
                    targetDirection = *a_direction;
                    blendTimer = 0.0f;
                }
            } else {
                *a_direction = targetDirection;
            }
        } else {
            *a_direction = targetDirection;
        }
    }

    if (blendTimer >= 1.0f) {
        return;
    }
    float duration = fSunShadowUpdateTime > 0.000001f ? fSunShadowUpdateTime : 0.000001f;
    float sum = g_realDeltaTime / duration + blendTimer;
    float t = sum < 1.0f ? sum : 1.0f;
    blendTimer = t;
    const NiPoint3* end = (cameraMoved == 1) ? a_direction : &targetDirection;
    const float fromX = fromDirection.x;
    const float fromY = fromDirection.y;
    const float fromZ = fromDirection.z;
    NiPoint3 result;
    result.x = (end->x - fromX) * t + fromX;
    result.y = (end->y - fromY) * t + fromY;
    result.z = (end->z - fromZ) * t + fromZ;
    *a_direction = result;
    a_direction->Unitize();
    if (!(blendTimer < 1.0f)) {
        fromDirection = targetDirection;
    }
}

// TODO body: RVA 0x157ed10, 3 bytes, BSShadowDirectionalLight::GetPassExtraParam.
std::uint32_t BSShadowDirectionalLight::GetPassExtraParam(std::uint32_t a_accumFlag)
{
    return a_accumFlag;
}

// GetIsFrustumOrDirectionalLight: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
bool BSShadowDirectionalLight::GetIsFrustumOrDirectionalLight()
{
    return true;
}

// GetIsDirectionalLight: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
bool BSShadowDirectionalLight::GetIsDirectionalLight()
{
    return true;
}

// GetNeedsClipPlanes: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
bool BSShadowDirectionalLight::GetNeedsClipPlanes()
{
    return true;
}

ShadowArray::~ShadowArray()
{
    if (data) {
        FreeArrayStorage(this);
        size = 0;
    }
}
