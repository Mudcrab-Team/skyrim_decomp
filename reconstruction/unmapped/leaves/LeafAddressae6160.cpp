// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6160, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6160 LeafAddressae6160::Address
#include "LeafAddressae6160.h"
extern unsigned char leaf_global;
void* LeafAddressae6160::Address() { return &leaf_global; }
