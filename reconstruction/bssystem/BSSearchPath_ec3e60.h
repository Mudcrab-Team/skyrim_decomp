// Source exposure: mixed (local binary analysis and public names). Build sse-steam-1-7-104.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSSearchPath","rationale":"vtable owner and slot; method spelling invented","slot":3},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Slot3 is synthesized from the bounded leaf template; GetNextSearchPath is read from the listing.
// BSSearchPath: EXE_RTTI
// Slot3: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// BSSearchPath::GetNextSearchPath: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); the vtable slot is not known
// BSSearchPath::nextIndex, ::path: GUESS(low); the counter at +0x8 and the 260-byte string at +0xc as used by GetNextSearchPath
#pragma once
#include <cstdint>
// Slot3: GUESS(low); method name inferred from vtable owner and slot
class BSSearchPath
{
public:
    virtual std::uint8_t Slot3() const;
    virtual bool GetNextSearchPath(char* a_dest, std::uint32_t a_size);

    std::uint32_t nextIndex;  // 08
    char path[0x104];         // 0C
};
