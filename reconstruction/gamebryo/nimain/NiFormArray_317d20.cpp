// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x317d20 NiFormArray::dtor_deleting
// CI hash: 0x317d20 ??_GNiFormArray@@UEAAPEAXI@Z
#include "NiFormArray_317d20.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiFormArray::NiFormArray() {}

// Releases the backing array storage before freeing the object when requested.
NiFormArray::~NiFormArray()
{
    NiFreeStorage(data);
}
