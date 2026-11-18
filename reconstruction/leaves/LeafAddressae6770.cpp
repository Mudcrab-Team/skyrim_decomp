// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6770, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6770 LeafAddressae6770::Address
#include "LeafAddressae6770.h"
extern unsigned char leaf_global;
void* LeafAddressae6770::Address() { return &leaf_global; }
