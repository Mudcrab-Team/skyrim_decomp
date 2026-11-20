// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x38e0c0 BGSEntryPointFunctionData::Unk_05
// 0x38ebb0 BGSEntryPointFunctionData::~BGSEntryPointFunctionData
#include "BGSEntryPointFunctionData.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSEntryPointFunctionData::BGSEntryPointFunctionData()
{
}

// TODO body: RVA 0x38e0c0, 6 bytes, BGSEntryPointFunctionData::Unk_05.
std::uint16_t BGSEntryPointFunctionData::Unk_05()
{
    return 0xffff;
}

BGSEntryPointFunctionData::~BGSEntryPointFunctionData()
{
}
