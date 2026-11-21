// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: the operator layout follows the observed append and threading operations.
// BSCompoundFrustum, functionOperators, freeOp, prethreaded: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// FrustumOpcode, FrustumOperator, FrustumOperatorArray, BeginOperatorGroup, EndOperatorGroup, AppendGroupDelimiter: GUESS(low)
#pragma once

#include <cstdint>

enum class FrustumOpcode : std::int32_t
{
    groupBegin = 5,
    groupEnd = 6
};

struct FrustumOperator
{
    FrustumOpcode opcode;
    std::uint32_t onTrue;
    std::uint32_t onFalse;
};
static_assert(sizeof(FrustumOperator) == 0xc, "operator record stride");

struct FrustumOperatorArray
{
    void Grow(std::int32_t capacity);

    FrustumOperator* data;
    std::uint8_t unknown08[8];
    std::int32_t capacity;
    std::uint32_t unknown14;
};
static_assert(sizeof(FrustumOperatorArray) == 0x18, "operator array stride");

class BSCompoundFrustum
{
public:
    void BeginOperatorGroup();
    void EndOperatorGroup();

private:
    void AppendGroupDelimiter(FrustumOpcode opcode);

    std::uint8_t unknown00[0x18];
    FrustumOperatorArray functionOperators;
    std::uint8_t unknown30[0x8c];
    std::int32_t freeOp;
    std::uint8_t unknownC0[5];
    bool prethreaded;
};
