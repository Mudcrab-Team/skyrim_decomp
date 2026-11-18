// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf67190, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf67190 LeafAddressf67190::Address
#include "LeafAddressf67190.h"
extern unsigned char leaf_global;
void* LeafAddressf67190::Address() { return &leaf_global; }
