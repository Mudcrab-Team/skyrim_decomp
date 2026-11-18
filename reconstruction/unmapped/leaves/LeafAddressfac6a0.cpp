// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfac6a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfac6a0 LeafAddressfac6a0::Address
#include "LeafAddressfac6a0.h"
extern unsigned char leaf_global;
void* LeafAddressfac6a0::Address() { return &leaf_global; }
