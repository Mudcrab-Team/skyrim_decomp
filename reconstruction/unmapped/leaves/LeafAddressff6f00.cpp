// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff6f00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff6f00 LeafAddressff6f00::Address
#include "LeafAddressff6f00.h"
extern unsigned char leaf_global;
void* LeafAddressff6f00::Address() { return &leaf_global; }
