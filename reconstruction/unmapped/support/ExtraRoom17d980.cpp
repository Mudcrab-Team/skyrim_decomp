// Source exposure: mixed (pinned image listing; CrashLogger PDB names; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr17d980::~RefPtr17d980 and RefTarget17d980::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17d980 ExtraRoom17d980::dtor_deleting
// CI hash: 0x17d980 ??_GExtraRoom17d980@@UEAAPEAXI@Z
#include "ExtraRoom17d980.h"

// PDB: the CrashLogger PDB names this ExtraRoom::dtor_deleting; ExtraRoom17d980 is a stand-in for ExtraRoom with a partial layout.
// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
ExtraRoom17d980::ExtraRoom17d980() = default;
