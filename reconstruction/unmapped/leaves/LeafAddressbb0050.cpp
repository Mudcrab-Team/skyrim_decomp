// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbb0050, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbb0050 LeafAddressbb0050::Address
#include "LeafAddressbb0050.h"
extern unsigned char leaf_global;
void* LeafAddressbb0050::Address() { return &leaf_global; }
