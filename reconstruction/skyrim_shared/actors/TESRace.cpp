// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x3ebda0 TESRace::GetPlayable
// 0x3e6250 TESRace::GetBodyPartData
// 0x3ebd80 TESRace::GetFormEditorID
// 0x3e64a0 TESRace::GetMovementType
// 0x3eb840 TESRace::~TESRace
#include "TESRace.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// The constructor is not compared: it is defined so that this unit emits the vftable and with it
// the deleting destructor.
TESRace::TESRace()
{
}

bool TESRace::GetPlayable() const
{
    return TestBit(data.flags, 0);
}

BGSBodyPartData* TESRace::GetBodyPartData()
{
    return bodyPartData ? bodyPartData : defaultBodyPartData;
}

const char* TESRace::GetFormEditorID() const
{
    return formEditorID.c_str();
}

BGSMovementType* TESRace::GetMovementType(std::int32_t a_index)
{
    BGSMovementType* type = baseMoveTypes[a_index];
    if (type) {
        return type;
    }
    return BGSDefaultObjectManager::GetDefaultMovementType(a_index);
}
