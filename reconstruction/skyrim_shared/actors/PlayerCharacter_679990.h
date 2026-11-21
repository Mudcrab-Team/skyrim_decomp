// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout from the observed player fall-damage caller.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// PlayerCharacter, AIProcess: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// currentProcess: OBSERVED
// ApplyShortFallDamage, CalculateFallDamage, DamageHealth, GetController, FallController: GUESS(low)
#pragma once

#include <cstdint>

struct FallController
{
    float GetFallDistance();
};

class AIProcess
{
public:
    FallController* GetController();
};

class PlayerCharacter
{
public:
    void ApplyShortFallDamage();

private:
    float CalculateFallDamage(float distance, float thresholdScale);
    void DamageHealth(float damage, void* source, bool useLandingFeedback);

    std::uint8_t unknown00[0xf8];
    AIProcess* currentProcess;
};
