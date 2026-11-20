// Source exposure: mixed (community headers; the pinned image listing).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original bodies written from the local listing; declarations from the pinned community headers.
// Adapted bodies: none
// 0x1581e30 ShadowArray::~ShadowArray
// 0x157ed10 BSShadowDirectionalLight::GetPassExtraParam
#include "BSShadowDirectionalLight.h"

// TODO body: RVA 0x157ed10, 3 bytes, BSShadowDirectionalLight::GetPassExtraParam.
std::uint32_t BSShadowDirectionalLight::GetPassExtraParam(std::uint32_t a_accumFlag)
{
    return a_accumFlag;
}

// GetIsFrustumOrDirectionalLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
bool BSShadowDirectionalLight::GetIsFrustumOrDirectionalLight()
{
    return true;
}

// GetIsDirectionalLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
bool BSShadowDirectionalLight::GetIsDirectionalLight()
{
    return true;
}

// GetNeedsClipPlanes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
