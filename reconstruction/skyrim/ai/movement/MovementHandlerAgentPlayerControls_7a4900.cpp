// Source exposure: mixed (permitted sibling game code; pinned-image observations).
// Code origin: adapted from labelled sibling game code with target-observed layout
// 0x7a4900 MovementHandlerAgentPlayerControls::SaveGame
// Adapted bodies: MovementHandlerAgentPlayerControls::SaveGame from fo4-private@1b765c70 (author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Movement/MovementHandlerAgentPlayerControls.cpp:160
// MovementHandlerAgentPlayerControls::SaveGame body: SIBLING(fo4-private@1b765c70, author-permission)
#include "MovementHandlerAgentPlayerControls_7a4900.h"

void MovementHandlerAgentPlayerControls::SaveGame(PathingWriter& stream) const
{
    stream.WriteUnsigned(inputType);
    stream.WriteFloat(dampenAccelerationMultiplier);
    stream.WriteBool(field4C);
}
