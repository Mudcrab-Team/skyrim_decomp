// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc495f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc495f0 LeafAddressc495f0::Address
#include "LeafAddressc495f0.h"
extern unsigned char leaf_global;
void* LeafAddressc495f0::Address() { return &leaf_global; }
