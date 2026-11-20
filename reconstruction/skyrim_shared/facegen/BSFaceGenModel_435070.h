// Origin: adapted public declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BSFaceGenModel: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <intrin.h>
#include <cstdint>
// NiRefObject, BSFaceGenModel, BSFaceGenModelMeshData, modelMeshData, _refCount, _pad0C, BSTSmartPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function435070, ReleaseMesh, ptr, refCount: GUESS(low)
class NiRefObject { public: virtual ~NiRefObject(); volatile std::uint32_t _refCount; std::uint32_t _pad0C; };
class BSFaceGenModelMeshData { public: volatile long refCount; };
template <class T> class BSTSmartPointer { public: T* ptr; };
void ReleaseMesh(BSFaceGenModelMeshData*);
class BSFaceGenModel : public NiRefObject {
public:
 BSFaceGenModel& Function435070(const BSFaceGenModel& rhs);
 BSTSmartPointer<BSFaceGenModelMeshData> modelMeshData;
};
