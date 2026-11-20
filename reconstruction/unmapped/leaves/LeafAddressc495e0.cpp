// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc495e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc495e0 LeafAddressc495e0::Address
#include "LeafAddressc495e0.h"
extern unsigned char leaf_global;
void* LeafAddressc495e0::Address() { return &leaf_global; }
