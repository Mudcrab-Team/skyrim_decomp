// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb7c210, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb7c210 LeafAddressb7c210::Address
#include "LeafAddressb7c210.h"
extern unsigned char leaf_global;
void* LeafAddressb7c210::Address() { return &leaf_global; }
