// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49880, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49880 LeafAddressc49880::Address
#include "LeafAddressc49880.h"
extern unsigned char leaf_global;
void* LeafAddressc49880::Address() { return &leaf_global; }
