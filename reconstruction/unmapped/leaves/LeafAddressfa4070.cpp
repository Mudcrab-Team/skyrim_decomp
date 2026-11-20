// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa4070, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa4070 LeafAddressfa4070::Address
#include "LeafAddressfa4070.h"
extern unsigned char leaf_global;
void* LeafAddressfa4070::Address() { return &leaf_global; }
