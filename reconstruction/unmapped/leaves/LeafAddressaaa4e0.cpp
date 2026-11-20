// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressaaa4e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xaaa4e0 LeafAddressaaa4e0::Address
#include "LeafAddressaaa4e0.h"
extern unsigned char leaf_global;
void* LeafAddressaaa4e0::Address() { return &leaf_global; }
