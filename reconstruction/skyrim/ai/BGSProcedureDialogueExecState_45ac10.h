// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Source exposure: binary-analysis.
// Code origin: original partial execution-state declaration inferred from the local listing.
// BGSProcedureDialogueExecState, unknown00, state: STANDIN GUESS(low); an opaque member begins at offset 0x18.
#pragma once
#include <cstdint>

namespace ReconstructedBGSProcedureDialogueExecState {

#include <cstdint>
class BGSProcedureDialogueExecState {
public:
    std::uint8_t* Function45ac10();
 std::uint8_t unknown00[0x18]; std::uint8_t state; };


}
