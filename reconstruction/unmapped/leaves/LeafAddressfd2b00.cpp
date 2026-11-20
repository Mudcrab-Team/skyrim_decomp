// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfd2b00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfd2b00 LeafAddressfd2b00::Address
#include "LeafAddressfd2b00.h"
extern unsigned char leaf_global;
void* LeafAddressfd2b00::Address() { return &leaf_global; }
