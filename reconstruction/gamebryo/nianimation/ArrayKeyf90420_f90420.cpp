// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf90420 ArrayKeyf90420::DeleteArray
#include "ArrayKeyf90420_f90420.h"

void ArrayKeyf90420::DeleteArray(AnimationKeyf90420* keys)
{
    delete[] static_cast<ArrayKeyf90420*>(keys);
}
