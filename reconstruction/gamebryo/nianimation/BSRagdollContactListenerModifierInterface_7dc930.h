// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// BSRagdollContactListenerModifierInterface: CRASHLOGGER_PDB(59818@2026.10.24)
// RagdollModifierBase7dc930, SingletonBase7dc930, instance, unk00: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class RagdollModifierBase7dc930
{
public:
    RagdollModifierBase7dc930();
    virtual ~RagdollModifierBase7dc930();
};
static_assert(sizeof(RagdollModifierBase7dc930) == 0x8, "RagdollModifierBase7dc930 size");

template <class T>
class SingletonBase7dc930
{
public:
    SingletonBase7dc930()
    {
        instance = static_cast<T*>(this);
    }

    static T* instance;

    std::uint8_t unk00[0x8];  // 00
};

class BSRagdollContactListenerModifierInterface :
    public RagdollModifierBase7dc930,
    public SingletonBase7dc930<BSRagdollContactListenerModifierInterface>
{
public:
    BSRagdollContactListenerModifierInterface();
    ~BSRagdollContactListenerModifierInterface() override;
};
static_assert(sizeof(BSRagdollContactListenerModifierInterface) == 0x10, "BSRagdollContactListenerModifierInterface size");
