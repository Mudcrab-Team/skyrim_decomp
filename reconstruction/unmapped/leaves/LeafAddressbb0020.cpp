// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbb0020, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbb0020 LeafAddressbb0020::Address
#include "LeafAddressbb0020.h"
extern unsigned char leaf_global;
void* LeafAddressbb0020::Address() { return &leaf_global; }
