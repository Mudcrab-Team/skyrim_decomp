// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf5b690, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf5b690 NiControllerSequence::GetRTTI
#include "LeafAddressf5b690.h"
extern unsigned char leaf_global;
void* LeafAddressf5b690::Address() { return &leaf_global; }
