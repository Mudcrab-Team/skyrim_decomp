// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0xff17c0 BSBound::LoadBinary
// 0xff1760 BSBound::CreateClone
// 0xff1b90 BSBound::GetRTTI
#include "BSBound.h"

// LoadBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BSBound::LoadBinary(NiStream& a_stream)
{
    NiExtraData::LoadBinary(a_stream);
    loaderA.Load(a_stream);
    loaderB.Load(a_stream);
}

// CreateClone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
NiObject* BSBound::CreateClone(NiCloningProcess& a_cloning)
{
    return this;
}

// GetRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
const NiRTTI* BSBound::GetRTTI() const
{
    return &NiRTTI_BSBound;
}
