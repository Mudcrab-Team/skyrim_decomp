// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb53010, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb53010 LeafAddressb53010::Address
#include "LeafAddressb53010.h"
extern unsigned char leaf_global;
void* LeafAddressb53010::Address() { return &leaf_global; }
