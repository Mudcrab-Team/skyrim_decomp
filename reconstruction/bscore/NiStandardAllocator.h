// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body written from the pinned image listing.
// NiStandardAllocator: EXE_RTTI
// VerifyAddress: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// Code origin: written for this project from the pinned image listing; no body adapted.
#pragma once
#include <cstdint>
// VerifyAddress: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class NiStandardAllocator
{
public:
    void Functioneafb10(void* a_mem, std::uint32_t a_alignment);
    virtual std::uint8_t VerifyAddress() const;
};

// NiStandardAllocatorInitObject: GUESS(low); the allocator shares this guard object with
// its initialization check, and the target only takes its address, so its layout is unobserved.
class NiStandardAllocatorInitObject;

// NiStandardAllocatorInitThreadHeader: GUESS(low); signature copied from the call site,
// which passes the guard object and the flag.
void NiStandardAllocatorInitThreadHeader(NiStandardAllocatorInitObject* a_object, std::int32_t* a_flag);

// NiStandardAllocatorDispatch: GUESS(low); signature copied from the call site,
// which passes the guard object, the block and a byte flag selecting the aligned-16 form.
void NiStandardAllocatorDispatch(NiStandardAllocatorInitObject* a_object, void* a_mem, bool a_aligned16);

// g_allocatorInitObject: GUESS(low); the guard object storage the target takes by address.
extern NiStandardAllocatorInitObject g_allocatorInitObject;
// g_allocatorInitFlag: GUESS(low); value 2 marks the guard initialized.
extern std::int32_t g_allocatorInitFlag;
