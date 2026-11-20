// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFaceGenModel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
// The base lifetime decrements the global object counter atomically.
class NiRefObject { public: virtual ~NiRefObject() { _InterlockedDecrement(&ms_totalObjects); } virtual void DeleteThis(); static volatile long ms_totalObjects; std::uint32_t refCount; };
class BSFaceGenModelMeshData; void ReleaseFaceMesh(BSFaceGenModelMeshData*);
struct FaceMeshOwner { BSFaceGenModelMeshData* data; ~FaceMeshOwner() { ReleaseFaceMesh(data); } };
class BSFaceGenModel : public NiRefObject { public: BSFaceGenModel(); ~BSFaceGenModel() override; FaceMeshOwner modelMeshData; std::uint32_t unknown18; }; static_assert(sizeof(BSFaceGenModel)==0x20,"face model size");

