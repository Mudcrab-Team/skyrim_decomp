// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// IEventCallbackFactory2fea70, IEventCallbackFactory2fea70::RegisterFactory: CRASHLOGGER_PDB(59818@2026.10.24)
// gFactoryHead2fea70: GUESS(low)
#pragma once

#include <cstddef>

extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* a_lhs, const char* a_rhs, std::size_t a_maxCount);

class IEventCallbackFactory2fea70
{
public:
    virtual ~IEventCallbackFactory2fea70();
    virtual void Slot01();
    virtual const char* GetName() const;
    virtual IEventCallbackFactory2fea70* GetNext() const;
    virtual void SetNext(IEventCallbackFactory2fea70* a_next);

    static void RegisterFactory(IEventCallbackFactory2fea70* a_factory);
};

extern IEventCallbackFactory2fea70* gFactoryHead2fea70;
