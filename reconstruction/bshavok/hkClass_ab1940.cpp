// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkClass: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionab1940: GUESS(low); provisional member name
// 0xab1940 hkClass::Functionab1940
// CI hash: 0xab1cc0 ?Functionab1cc0@hkClass@@QEAAXI@Z
// CI hash: 0xab1940 ?Functionab1940@hkClass@@QEAAPEAUMemberab1940@@PEBD@Z
// CI hash: 0xab1ba0 ?Functionab1ba0@hkClass@@QEAAPEAUMemberab1ba0@@PEBD@Z
#include "hkClass_ab1940.h"

// Guess: Find a reflected member by its name.
Memberab1940* hkClass::Functionab1940(const char* name)
{
    for (int i = 0; i < GetEnumCount(); ++i) {
        auto* member = GetEnum(i);
        if (CompareMemberName(member->name, name) == 0) { return member; }
    }
    return nullptr;
}

// 0xab1ba0 hkClass::Functionab1ba0
// Guess: Find a reflected member by its name.
Memberab1ba0* hkClass::Functionab1ba0(const char* name)
{
    for (int i = 0; i < GetMemberCount(); ++i) {
        auto* member = GetMember(i);
        if (CompareMemberName(member->name, name) == 0) { return member; }
    }
    return nullptr;
}

// 0xab1cc0 hkClass::Functionab1cc0
// Guess: Set the reflected object size.
void hkClass::Functionab1cc0(unsigned value)
{
    objectSize = value;
}
