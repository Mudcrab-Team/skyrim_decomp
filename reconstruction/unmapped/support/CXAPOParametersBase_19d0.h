// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// CXAPOParametersBase, CXAPOParametersBase::~CXAPOParametersBase: CRASHLOGGER_PDB(59818@2026.10.24)
// CXAPOParametersBase::unk00, CXAPOParametersBase::m_pParameterBlocks: GUESS
#pragma once

#include <cstdint>

// The C runtime release routine, imported from the runtime library.
extern "C" __declspec(dllimport) void __cdecl free(void* a_block);

class CXAPOParametersBase
{
  public:
    ~CXAPOParametersBase();

    std::uint8_t unk00[0x18];
    void* m_pParameterBlocks;
};
