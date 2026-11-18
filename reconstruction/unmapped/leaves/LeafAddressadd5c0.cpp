// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadd5c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadd5c0 LeafAddressadd5c0::Address
#include "LeafAddressadd5c0.h"
extern unsigned char leaf_global;
void* LeafAddressadd5c0::Address() { return &leaf_global; }
