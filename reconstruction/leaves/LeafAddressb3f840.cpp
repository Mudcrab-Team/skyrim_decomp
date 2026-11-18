// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3f840, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3f840 LeafAddressb3f840::Address
#include "LeafAddressb3f840.h"
extern unsigned char leaf_global;
void* LeafAddressb3f840::Address() { return &leaf_global; }
