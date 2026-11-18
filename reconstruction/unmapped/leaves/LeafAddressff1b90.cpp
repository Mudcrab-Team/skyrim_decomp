// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff1b90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff1b90 BSBound::GetRTTI
#include "LeafAddressff1b90.h"
extern unsigned char leaf_global;
void* LeafAddressff1b90::Address() { return &leaf_global; }
