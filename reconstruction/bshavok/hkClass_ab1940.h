// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkClass: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionab1940: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Memberab1940, CompareMemberName: GUESS(low) STANDIN; reflected member and name comparison
struct Memberab1940 { const char* name; };
// Memberab1ba0: GUESS(low) STANDIN; reflected member declaration
struct Memberab1ba0 { const char* name; };
extern "C" int CompareMemberName(const char*, const char*);

class hkClass
{
public:
    std::uint8_t unknown00[0x10];
    unsigned objectSize;
    int GetEnumCount();
    Memberab1940* GetEnum(int);
    int GetMemberCount();
    Memberab1ba0* GetMember(int);
    Memberab1940* Functionab1940(const char* name);
    Memberab1ba0* Functionab1ba0(const char* name);
    void Functionab1cc0(unsigned value);
};
