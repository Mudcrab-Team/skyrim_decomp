// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// Code origin: written for this reconstruction from the listing; base class and destructor are guesses.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementTweenerAgentNodeFollower.cpp:64
// MovementTweenerAgentNodeFollower, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
#pragma once
struct BSFixedString { const char* data; BSFixedString(const char*); ~BSFixedString(); };
class MovementTweenerAgent { public: virtual ~MovementTweenerAgent(); };
class MovementTweenerAgentNodeFollower : public MovementTweenerAgent
{
public:
    virtual ~MovementTweenerAgentNodeFollower() {}
    void Function7ab9a0();
    static const BSFixedString &QClassAgentType();
};
