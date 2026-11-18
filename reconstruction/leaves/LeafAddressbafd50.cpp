// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbafd50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbafd50 LeafAddressbafd50::Address
#include "LeafAddressbafd50.h"
extern unsigned char leaf_global;
void* LeafAddressbafd50::Address() { return &leaf_global; }
