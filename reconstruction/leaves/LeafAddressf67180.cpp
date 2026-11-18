// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf67180, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf67180 LeafAddressf67180::Address
#include "LeafAddressf67180.h"
extern unsigned char leaf_global;
void* LeafAddressf67180::Address() { return &leaf_global; }
