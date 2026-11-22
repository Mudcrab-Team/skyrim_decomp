// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; MatchCondition written from the pinned image listing, declarations from community headers and the CrashLogger PDB name.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x153250 MagicItemFindKeywordFunctor::MatchCondition
// Adapted bodies: none
#include "MagicItemFindKeywordFunctor.h"

// Ask the keyword matcher held by the argument whether this functor's keyword matches.
bool MagicItemFindKeywordFunctor::MatchCondition(ArgType* a_arg)
{
    if (a_arg && a_arg->field10->matcher.Matches(field18))
        return true;
    return false;
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
MagicItemFindKeywordFunctor::MagicItemFindKeywordFunctor()
{
}

// RVA 0x152790, 43 bytes, MagicItemFindKeywordFunctor::~MagicItemFindKeywordFunctor; compared as the
// scalar deleting destructor. The target stores the vftable and frees the object itself, so the
// complete destructor is empty.
MagicItemFindKeywordFunctor::~MagicItemFindKeywordFunctor()
{
}
