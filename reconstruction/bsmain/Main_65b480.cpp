// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Main: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function65b480: GUESS(low); provisional member name
// 0x65b480 Main::Function65b480
// CI hash: 0x65b480 ?Function65b480@Main@@QEAAX_N@Z
#include "Main_65b480.h"

// Guess: Finish the main work transition and optionally request a path load.
void Main::Function65b480(bool load)
{
    if(mainMode65b480) { Stop(); }
    worker65b480->Run(0,0,0);
    FinishMainWork();
    FinishMainState();
    if(load && mainPath65b480 && mainPath65b480[0]) { loader65b480->Load(mainPath65b480,0,~0u); }
}
