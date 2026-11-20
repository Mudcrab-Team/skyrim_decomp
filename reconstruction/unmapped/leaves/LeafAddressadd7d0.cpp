// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadd7d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadd7d0 LeafAddressadd7d0::Address
#include "LeafAddressadd7d0.h"
extern unsigned char leaf_global;
void* LeafAddressadd7d0::Address() { return &leaf_global; }
