// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Main: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function65b480: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Worker65b480, Loader65b480, mainMode65b480, worker65b480, mainPath65b480, loader65b480, FinishMainWork, FinishMainState: GUESS(low) STANDIN; main-thread work transition
struct Worker65b480 { void Run(unsigned,unsigned,unsigned); };
struct Loader65b480 { void Load(const char*,unsigned,unsigned); };
extern bool mainMode65b480;
extern Worker65b480* worker65b480;
extern const char* mainPath65b480;
extern Loader65b480* loader65b480;
extern "C" void FinishMainWork();
extern "C" void FinishMainState();

class Main
{
public:
    void Stop();

    void Function65b480(bool load);
};
