// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadd9f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadd9f0 LeafAddressadd9f0::Address
#include "LeafAddressadd9f0.h"
extern unsigned char leaf_global;
void* LeafAddressadd9f0::Address() { return &leaf_global; }
