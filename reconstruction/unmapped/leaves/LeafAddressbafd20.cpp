// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbafd20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbafd20 LeafAddressbafd20::Address
#include "LeafAddressbafd20.h"
extern unsigned char leaf_global;
void* LeafAddressbafd20::Address() { return &leaf_global; }
