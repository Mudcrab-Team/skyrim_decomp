// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6580, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6580 LeafAddressae6580::Address
#include "LeafAddressae6580.h"
extern unsigned char leaf_global;
void* LeafAddressae6580::Address() { return &leaf_global; }
