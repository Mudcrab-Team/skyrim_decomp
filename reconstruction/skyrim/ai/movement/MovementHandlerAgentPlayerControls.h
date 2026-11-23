// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: QClassAgentType adapted from the cited game-code body under anonymous author permission; the rest written for this reconstruction from the listing.
// Licence: fo4-private reused with author permission conditional on anonymity.
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Movement/MovementHandlerAgentPlayerControls.cpp:129
// MovementHandlerAgentPlayerControls, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// MovementHandlerAgentPlayerControls::Function7a49a0: GUESS(low)
#pragma once
struct BSFixedString { const char* data; BSFixedString(const char*); ~BSFixedString(); };
class MovementHandlerAgentPlayerControls {
public:
    static const BSFixedString &QClassAgentType();
    void Function7a49a0(float a_newValue);
private:
    char _unk00[0x28];
    float _unk28;
};
