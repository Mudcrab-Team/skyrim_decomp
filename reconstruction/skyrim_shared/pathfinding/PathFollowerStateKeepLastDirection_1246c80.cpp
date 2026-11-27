// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0x1246c80 PathFollowerStateKeepLastDirection::SaveGame
#include "PathFollowerStateKeepLastDirection_1246c80.h"

// Serializes the saved direction vector, timer, and pathing reference identifier.
void PathFollowerStateKeepLastDirection::SaveGame(BSPathingStreamWrite* a_stream, IPathingRefSaver* a_refSaver)
{
    a_stream->WriteFloat(direction.x);
    a_stream->WriteFloat(direction.y);
    a_stream->WriteFloat(direction.z);
    a_stream->WriteFloat(unk14);
    const std::uint32_t id = a_refSaver->GetRefId(unk18);
    a_stream->WriteUInt32(id);
}
