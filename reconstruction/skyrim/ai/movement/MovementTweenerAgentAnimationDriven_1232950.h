// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original typed reconstruction with provisional member and interface names.
// SPDX-License-Identifier: CC0-1.0
// MovementTweenerAgentAnimationDriven: STANDIN GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
#include <atomic>
#include <intrin.h>
#include <Windows.h>
class MovementBase1232950 { public: virtual ~MovementBase1232950();
virtual void Unknown1();
virtual void Unknown2();
virtual void Unknown3();
virtual void Unknown4();
virtual void Unknown5();
virtual void Unknown6();
virtual void Unknown7();
virtual void Unknown8();
virtual void Unknown9();
virtual void Unknown10();
virtual void Unknown11();
virtual void Unknown12();
 std::uint8_t unknown08[16]; };
class TweenInterface1232950 { public: virtual ~TweenInterface1232950();
virtual void Unknown1();
virtual void Unknown2();
virtual void Unknown3();
 };
class MovementTweenerAgentAnimationDriven : public MovementBase1232950, public TweenInterface1232950 { public: virtual ~MovementTweenerAgentAnimationDriven();
void Unknown3() override;
 };
static_assert(sizeof(MovementTweenerAgentAnimationDriven) == 32, "complete object extent");
