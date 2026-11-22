// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// NiBlendTransformInterpolator: EXE_RTTI
// IsTransformValueSupported: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0xf67e80 NiBlendTransformInterpolator::IsTransformValueSupported
// 0xf67ed0 NiBlendTransformInterpolator::InterpolatorIsCorrectType
// InterpolatorIsCorrectType: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); FNV names the other blend interpolators' functions NiBlend*Interpolator_InterpolatorIsCorrectType
#include "NiBlendTransformInterpolator.h"
// IsTransformValueSupported: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t NiBlendTransformInterpolator::IsTransformValueSupported() const
{
    return 0x1;
}


bool NiBlendTransformInterpolator::InterpolatorIsCorrectType(NiInterpolator* a_interpolator) const
{
    return a_interpolator->IsTransformValueSupported();
}
