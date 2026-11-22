// Source exposure: mixed (local binary analysis and public names).
// 0xfa0a00 compared function
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// NiPSysModifierCtlr: EXE_RTTI
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class NiStream;

// NiPSysModifierBase, SaveCtlrMember: GUESS(low); callees resolved from the local listing
class NiPSysModifierBase
{
public:
    virtual void Unk();  // GUESS(low); keeps the primary vptr at offset zero
    void SaveBinary(NiStream& a_stream) throw();
};

void SaveCtlrMember(NiStream& a_stream, void** a_member) throw();

class NiPSysModifierCtlr : public NiPSysModifierBase
{
public:
    void SaveBinary(NiStream& a_stream) throw();
    virtual void* GetCtlrID() const;
    std::uint8_t padding[0x48];
    void* member;
};
