// Source exposure: mixed (pinned image listing; CrashLogger PDB names; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr17c430::~RefPtr17c430 and RefTarget17c430::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c430 ExtraCell3D17c430::dtor_deleting
// CI hash: 0x17c430 ??_GExtraCell3D17c430@@UEAAPEAXI@Z
#include "ExtraCell3D17c430.h"

// PDB: the CrashLogger PDB names this ExtraCell3D::dtor_deleting; ExtraCell3D17c430 is a stand-in for ExtraCell3D with a partial layout.
// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
ExtraCell3D17c430::ExtraCell3D17c430() = default;
