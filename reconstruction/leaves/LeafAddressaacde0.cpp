// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressaacde0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xaacde0 LeafAddressaacde0::Address
#include "LeafAddressaacde0.h"
extern unsigned char leaf_global;
void* LeafAddressaacde0::Address() { return &leaf_global; }
