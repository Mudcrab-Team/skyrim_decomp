// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xf6fd10 Functionf6fd10
// Adapted bodies: none
#include "FreeFunction_f6fd10.h"

// Calls HelperA_f6fd10 on (target, entry), then HelperB_f6fd10 on (&entry->field04, target).
void Functionf6fd10(void* target, Entry_f6fd10* entry)
{
    HelperA_f6fd10(target, entry);
    HelperB_f6fd10(&entry->field04, target);
}
