// Licence: uses some member names from powerof3/CommonLibSSE (see the header), so this file is GPL-3.0.
// Source exposure: mixed. Drafted from local listings of the pinned image with
// Code origin: Stamped as a twin of matched 0x692ea0 (skyrim_shared/actors/Character): source copied, names replaced by placeholders.
// types from the header beside this file.
// 0x80ea60 Owner80ea60::Function80ea60
#include "Owner80ea60.h"

// The constructor is not compared: it is defined so that this unit emits the vftable and with
// it the deleting destructor, as the original unit did. ~Owner80ea60 itself is declared, not defined:
// the deleting destructor calls it out of line (the plain destructor lives in another unit).
Owner80ea60::Owner80ea60()
{
}

// guess: same compiled code as matched 0x692ea0 apart from relocated fields; its role here is not established.
float Owner80ea60::Function80ea60() const
{
    return unk48;
}
