// Source exposure: mixed (pinned image listing and community declarations; names from CharmedBaryon/CommonLibSSE-NG b93280e, MIT).
// Code origin: original reconstruction from the pinned image and community declarations.
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x264370 BGSMovableStatic::InitItemImpl
// 0x264444 BGSMovableStatic::dtor
// 0x2640a0 BGSMovableStatic::InitializeData
#include "BGSMovableStatic.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
static bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the destructor thunks. Its body is a minimal stand-in.
BGSMovableStatic::BGSMovableStatic()
{
}

BGSMovableStatic::~BGSMovableStatic()
{
}

void BGSMovableStatic::InitializeData()
{
    soundLoop = nullptr;
}

void BGSMovableStatic::InitItemImpl()
{
    if (TestBit(formFlags, 3)) {
        return;
    }
    BGSMovableStatic* self = this;
    TESForm* form = this;
    InitDestructibleObjectFormState(reinterpret_cast<BGSDestructibleObjectForm*>(reinterpret_cast<std::uint8_t*>(self) + 0x10), form);  // 0x10 destructible object component
    InitModelTextureSwapState(reinterpret_cast<void*>(reinterpret_cast<std::uint8_t*>(self) + 0x50), form);  // 0x50 model texture swap component
    // soundLoop holds a form id until this step, then the looked-up descriptor form.
    std::uint32_t id = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(self->soundLoop));
    if (id != 0 && form != nullptr) {
        AddCompileIndex(id, GetFile(form, -1));
        self->soundLoop = static_cast<BGSSoundDescriptorForm*>(LookupByID(id));
    }
    SetFormFlag(self, true);
}
