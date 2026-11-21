// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// NiStreamSaveBinary, NiStreamLoadBinary, NiBinaryStreamLoad: GUESS(low); free 4-byte stream helpers named after Gamebryo's load and save helpers; the inventory files them under this class
// 0xf9c400 NiPSysGravityModifier::LinkObject
// 0xf9d760 NiPSysGravityModifier::~NiPSysGravityModifier
// 0xf9d720 NiStreamSaveBinary
// 0xf9d650 NiBinaryStreamLoad
// 0xf9d6d0 NiStreamLoadBinary
#include "NiPSysGravityModifier.h"

void NiPSysGravityModifier::LinkObject(NiStream& a_stream)
{
    NiPSysModifier::LinkObject(a_stream);
    field30 = a_stream.ReadLinkID();
}

// Not compared: its definition places the class vftable in this unit. The destructor is declared,
// not defined, as in the listing, which calls the complete destructor in a separate function
// (cookbook rule 14).
NiPSysGravityModifier::NiPSysGravityModifier()
{
}

void NiStreamSaveBinary(NiStream& a_stream, const std::uint32_t& a_value)
{
    a_stream.oStr->write(&a_value, 1);
}

void NiBinaryStreamLoad(NiBinaryStream& a_stream, std::uint32_t& a_value)
{
    std::uint32_t loaded;
    a_stream.read(&loaded, 1);
    a_value = loaded;
}

void NiStreamLoadBinary(NiStream& a_stream, std::uint32_t& a_value)
{
    NiBinaryStreamLoad(*a_stream.iStr, a_value);
}
