/*
 * Main: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x656c20 30 bytes; RVA 0x659e20 30 bytes; RVA 0x65b340 33 bytes; RVA 0x65b4f0 34 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * The compared functions and callees have inferred signatures and unverified ownership.
 * No external body or declaration has yet been adapted. Stand-ins are unverified.
 */
// Main: STANDIN EXE_RTTI
// Function656c20, Function659e20, Function65b340, Function65b4f0, ServiceOne, ServiceTwo, ProcessOne, ProcessTwo, ProcessThree, ProcessFour, FinishOne, FinishTwo, serviceOne, serviceTwo, setting: GUESS(low)
#pragma once

#include <cstdint>
class ServiceOne;
class ServiceTwo;
extern ServiceOne* serviceOne;
extern ServiceTwo* serviceTwo;
extern std::uint32_t setting;
void ProcessOne(ServiceOne*);
void ProcessTwo();
void ProcessThree();
void ProcessFour(std::uint32_t);
void ProcessService(ServiceTwo*);
class Main {
public:
    void Function656c20();
    void Function659e20();
    void Function65b340();
    void Function65b4f0();
    void FinishOne();
    void FinishTwo();
};
// ProcessService: GUESS(low)
