// Origin: adapted public declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BSFaceGenModel: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x435070 BSFaceGenModel::Function435070
#include "BSFaceGenModel_435070.h"
BSFaceGenModel& BSFaceGenModel::Function435070(const BSFaceGenModel& rhs) {
 auto incoming = rhs.modelMeshData.ptr;
 auto previous = modelMeshData.ptr;
 if (incoming != previous) {
  // Shared mesh ownership requires an atomic reference increment.
  if (incoming) _InterlockedIncrement(&incoming->refCount);
  modelMeshData.ptr = incoming;
  ReleaseMesh(previous);
 }
 return *this;
}
