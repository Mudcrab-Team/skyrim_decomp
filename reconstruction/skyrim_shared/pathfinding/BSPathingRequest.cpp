// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// Code origin: brown-room reconstruction from disassembly
// SPDX-License-Identifier: CC0-1.0
// 0x4e3290 PathingRequest::~PathingRequest
// 0x11cbe10 Leaf11cbe10::Invoke
#include "BSPathingRequest.h"

// BSPathingRequestBase: STANDIN GUESS(low); the pinned class's own destructor is at 0x11cb9c0,
// called out of line by the compared destructor. Declared only, so the call stays a tail jump.
class BSPathingRequestBase
{
public:
    virtual ~BSPathingRequestBase();
};

// PathingRequest: EXE_RTTI; the vftable the compared destructor stores is also stored by the
// constructor at 0x4e3260, which the CrashLogger PDB names PathingRequest::PathingRequest.
class PathingRequest : public BSPathingRequestBase
{
public:
    PathingRequest();
    ~PathingRequest() override;
};

// Not compared: defined so that the compiler emits the vftable and the plain destructor.
PathingRequest::PathingRequest() = default;

// Stores this class's vftable, then tail-calls the base destructor.
PathingRequest::~PathingRequest()
{
}

// RVA 0x11cbe10, 3 bytes, BSPathingRequest::CheckValid. The target is a bare return.
void BSPathingRequest::CheckValid()
{
}
