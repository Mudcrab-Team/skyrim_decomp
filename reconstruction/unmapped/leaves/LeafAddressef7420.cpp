// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef7420, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef7420 NiStringExtraData::GetRTTI
#include "LeafAddressef7420.h"
extern unsigned char leaf_global;
void* LeafAddressef7420::Address() { return &leaf_global; }
