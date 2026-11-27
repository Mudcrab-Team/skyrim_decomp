// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcf54a0 GFxValue::ObjectInterface::GetArraySize
// Adapted bodies: none
#include "ObjectInterface.h"

std::uint32_t GFxValue::ObjectInterface::GetArraySize(void* a_data) const
{
    // An array value's data is the object interface of the array object.
    GASArrayObject* array = static_cast<GASArrayObject*>(static_cast<GASObjectInterface*>(a_data));
    return array->unk78;
}
