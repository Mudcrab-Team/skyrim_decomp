// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// TweenerBaseStandIn: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementTweenerAgentNodeFollower.cpp:64
// MovementTweenerAgentNodeFollower, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// MovementTweenerAgentNodeFollower: EXE_RTTI
// ~MovementTweenerAgentNodeFollower: GUESS(medium)
// Code origin: mixed; QClassAgentType adapted from the cited sibling body, the destructor and stand-ins original (pinned listing, target RTTI contract)
#pragma once
struct BSFixedString { const char* data; BSFixedString(const char*); ~BSFixedString(); };
class TweenerBaseStandIn { public: virtual ~TweenerBaseStandIn(); };
class MovementTweenerAgentNodeFollower : public TweenerBaseStandIn
{
public:
    static const BSFixedString &QClassAgentType();
    ~MovementTweenerAgentNodeFollower() override;
};
