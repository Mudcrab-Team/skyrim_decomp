// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresseac4a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xeac4a0 LeafAddresseac4a0::Address
#include "LeafAddresseac4a0.h"
extern unsigned char leaf_global;
void* LeafAddresseac4a0::Address() { return &leaf_global; }
