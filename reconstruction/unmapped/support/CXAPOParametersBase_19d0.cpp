// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x19d0 CXAPOParametersBase::~CXAPOParametersBase
#include "CXAPOParametersBase_19d0.h"

// Frees the allocated parameter block buffer if present.
CXAPOParametersBase::~CXAPOParametersBase()
{
    if (m_pParameterBlocks)
    {
        free(m_pParameterBlocks);
        m_pParameterBlocks = nullptr;
    }
}
