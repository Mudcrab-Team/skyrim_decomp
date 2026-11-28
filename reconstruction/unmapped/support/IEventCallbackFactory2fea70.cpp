// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// 0x2fea70 IEventCallbackFactory2fea70::RegisterFactory
// Adapted bodies: none
#include "IEventCallbackFactory2fea70.h"

// Guess: prepend a factory to the global list if no factory with the same name is registered.
void IEventCallbackFactory2fea70::RegisterFactory(IEventCallbackFactory2fea70* a_factory)
{
    for (IEventCallbackFactory2fea70* cur = gFactoryHead2fea70; cur != nullptr; cur = cur->GetNext())
    {
        if (_strnicmp(cur->GetName(), a_factory->GetName(), 0x50) == 0)
        {
            return;
        }
    }
    a_factory->SetNext(gFactoryHead2fea70);
    gFactoryHead2fea70 = a_factory;
}
