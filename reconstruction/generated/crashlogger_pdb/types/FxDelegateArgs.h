// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FxDelegateArgs; size 0x38
#pragma once

#include "GFxValue.h"
struct FxDelegateHandler_ccd4e5d3;
struct GFxMovieView;
struct FxDelegateArgs {
    GFxValue _responseID;
    FxDelegateHandler_ccd4e5d3* _handler;
    GFxMovieView* _movieView;
    GFxValue* _args;
    unsigned int _numArgs;
    unsigned int _pad34;
};
static_assert(sizeof(FxDelegateArgs) == 56, "FxDelegateArgs layout differs from the PDB");
