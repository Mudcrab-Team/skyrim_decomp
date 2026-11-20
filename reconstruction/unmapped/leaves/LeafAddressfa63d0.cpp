// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa63d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa63d0 LeafAddressfa63d0::Address
#include "LeafAddressfa63d0.h"
extern unsigned char leaf_global;
void* LeafAddressfa63d0::Address() { return &leaf_global; }
