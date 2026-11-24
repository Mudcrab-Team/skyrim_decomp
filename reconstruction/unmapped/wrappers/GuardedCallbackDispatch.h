// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: adapted from the repository's guarded static-callback wrapper template.
// GuardedCallbackDispatch, guard and handler: GUESS(low) STANDIN
// Adapted bodies: guarded callback condition and call.
#pragma once

using GuardedCallback = void (*)(void*);

extern "C" unsigned long long GuardedCallbackRegistration;
extern "C" GuardedCallback GuardedCallbackHandler;

struct GuardedCallbackDispatch
{
    static void Dispatch(void* argument)
    {
        if (GuardedCallbackRegistration != 0 && GuardedCallbackHandler != nullptr)
        {
            GuardedCallbackHandler(argument);
        }
    }
};
