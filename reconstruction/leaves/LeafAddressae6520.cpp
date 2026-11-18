// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6520, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6520 LeafAddressae6520::Address
#include "LeafAddressae6520.h"
extern unsigned char leaf_global;
void* LeafAddressae6520::Address() { return &leaf_global; }
