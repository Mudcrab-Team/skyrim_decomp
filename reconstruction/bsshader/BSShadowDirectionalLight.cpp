// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
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
