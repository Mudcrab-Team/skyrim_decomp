// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbaff00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbaff00 LeafAddressbaff00::Address
#include "LeafAddressbaff00.h"
extern unsigned char leaf_global;
void* LeafAddressbaff00::Address() { return &leaf_global; }
