// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfd2b10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfd2b10 LeafAddressfd2b10::Address
#include "LeafAddressfd2b10.h"
extern unsigned char leaf_global;
void* LeafAddressfd2b10::Address() { return &leaf_global; }
