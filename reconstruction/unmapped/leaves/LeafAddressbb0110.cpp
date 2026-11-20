// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbb0110, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbb0110 LeafAddressbb0110::Address
#include "LeafAddressbb0110.h"
extern unsigned char leaf_global;
void* LeafAddressbb0110::Address() { return &leaf_global; }
