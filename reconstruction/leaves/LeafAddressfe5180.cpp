// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfe5180, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfe5180 LeafAddressfe5180::Address
#include "LeafAddressfe5180.h"
extern unsigned char leaf_global;
void* LeafAddressfe5180::Address() { return &leaf_global; }
