// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbb0340, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbb0340 LeafAddressbb0340::Address
#include "LeafAddressbb0340.h"
extern unsigned char leaf_global;
void* LeafAddressbb0340::Address() { return &leaf_global; }
