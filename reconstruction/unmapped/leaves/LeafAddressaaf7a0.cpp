// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressaaf7a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xaaf7a0 LeafAddressaaf7a0::Address
#include "LeafAddressaaf7a0.h"
extern unsigned char leaf_global;
void* LeafAddressaaf7a0::Address() { return &leaf_global; }
