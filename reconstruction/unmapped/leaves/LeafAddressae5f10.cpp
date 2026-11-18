// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5f10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5f10 LeafAddressae5f10::Address
#include "LeafAddressae5f10.h"
extern unsigned char leaf_global;
void* LeafAddressae5f10::Address() { return &leaf_global; }
