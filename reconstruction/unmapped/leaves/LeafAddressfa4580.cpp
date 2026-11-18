// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa4580, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa4580 LeafAddressfa4580::Address
#include "LeafAddressfa4580.h"
extern unsigned char leaf_global;
void* LeafAddressfa4580::Address() { return &leaf_global; }
