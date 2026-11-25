// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBSplineBasisData: SIBLING(fo4-private@1b765c70, author-permission)
// NiBSplineBasisData size: CRASHLOGGER_PDB(59818@2026.10.24); name lead, identity unproven
// Base and storage names: GUESS(low); stand-ins for observed layout
// BasisDtorLeaff76af0, BasisObjectBase: GUESS(low); stand-in names
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gBasisObjectCount;

class BasisObjectBase
{
public:
    virtual ~BasisObjectBase();
    std::uint64_t objectState;
};

class BasisDtorLeaff76af0 : public BasisObjectBase
{
public:
    BasisDtorLeaff76af0();
    ~BasisDtorLeaff76af0() override;
    std::uint64_t basisState[4];
};
