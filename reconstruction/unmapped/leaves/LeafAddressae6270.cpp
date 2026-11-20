// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6270, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6270 LeafAddressae6270::Address
#include "LeafAddressae6270.h"
extern unsigned char leaf_global;
void* LeafAddressae6270::Address() { return &leaf_global; }
