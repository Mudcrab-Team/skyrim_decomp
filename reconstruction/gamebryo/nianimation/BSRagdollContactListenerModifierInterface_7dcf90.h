// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// BSRagdollContactListenerModifierInterface: CRASHLOGGER_PDB(59818@2026.10.24)
// RagdollModifierBase7dcf90, SingletonBase7dcf90, instance, unk00: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class RagdollModifierBase7dcf90
{
public:
    RagdollModifierBase7dcf90();
    virtual ~RagdollModifierBase7dcf90();
};
static_assert(sizeof(RagdollModifierBase7dcf90) == 0x8, "RagdollModifierBase7dcf90 size");

template <class T>
class SingletonBase7dcf90
{
public:
    ~SingletonBase7dcf90()
    {
        instance = nullptr;
    }

    static T* instance;

    std::uint8_t unk00[0x8];  // 00
};

class BSRagdollContactListenerModifierInterface :
    public RagdollModifierBase7dcf90,
    public SingletonBase7dcf90<BSRagdollContactListenerModifierInterface>
{
public:
    BSRagdollContactListenerModifierInterface();
    ~BSRagdollContactListenerModifierInterface() override {}
};
static_assert(sizeof(BSRagdollContactListenerModifierInterface) == 0x10, "BSRagdollContactListenerModifierInterface size");
