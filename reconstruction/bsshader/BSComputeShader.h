// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSComputeShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
// The object counter is decremented atomically at the end of its base lifetime.
class NiRefObject { public: virtual ~NiRefObject() { _InterlockedDecrement(&ms_totalObjects); } virtual void DeleteThis(); static volatile long ms_totalObjects; std::uint32_t refCount; };
struct ShaderEntry { std::uint32_t key; void* value; ShaderEntry* next; };
struct ShaderTableTail { ~ShaderTableTail(); std::uint32_t unknown00,capacity,freeCount,good; ShaderEntry* sentinel; std::uint64_t allocatorState; ShaderEntry* entries; };
class BSReloadShaderI { public: virtual void ReloadShaders(void*)=0; };
class BSComputeShader : public NiRefObject, public BSReloadShaderI { public: BSComputeShader(); ~BSComputeShader() override; void ReloadShaders(void*) override; virtual void Dispatch(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t); const char* name; std::uint64_t tableUnknown00; ShaderTableTail table; };
static_assert(sizeof(BSComputeShader)==0x50,"compute shader size");
void ReleaseShaderName(const char*); extern std::uint64_t Renderer; extern const char ShaderErrorFormat[];
void BindComputeShader(void*,void*,std::uint32_t,std::uint32_t,std::uint32_t); int ShaderFormat(char*,std::size_t,const char*,...);
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char*);

