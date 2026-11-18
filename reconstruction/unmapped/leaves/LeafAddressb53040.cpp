// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb53040, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb53040 LeafAddressb53040::Address
#include "LeafAddressb53040.h"
extern unsigned char leaf_global;
void* LeafAddressb53040::Address() { return &leaf_global; }
