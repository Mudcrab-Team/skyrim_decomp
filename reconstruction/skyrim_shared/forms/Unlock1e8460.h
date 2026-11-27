// Source exposure: binary-analysis
// Unlock1e8460: GUESS(low) STANDIN; original owner is unknown
// Function1e8460: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
class FullName1e8460 { public: virtual ~FullName1e8460(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4(); virtual const char* GetName(); };
extern const char formType, nameType;
extern const char emptyName[];
extern void* RuntimeCast(void*, long, const void*, const void*, int);

class Unlock1e8460 {
public:
    static const char* Function1e8460(void* form);
};
