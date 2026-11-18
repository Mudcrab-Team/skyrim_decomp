// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf84780, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf84780 LeafAddressf84780::Address
#include "LeafAddressf84780.h"
extern unsigned char leaf_global;
void* LeafAddressf84780::Address() { return &leaf_global; }
