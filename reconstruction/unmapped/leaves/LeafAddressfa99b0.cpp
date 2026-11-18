// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa99b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa99b0 LeafAddressfa99b0::Address
#include "LeafAddressfa99b0.h"
extern unsigned char leaf_global;
void* LeafAddressfa99b0::Address() { return &leaf_global; }
