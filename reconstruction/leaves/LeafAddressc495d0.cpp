// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc495d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc495d0 LeafAddressc495d0::Address
#include "LeafAddressc495d0.h"
extern unsigned char leaf_global;
void* LeafAddressc495d0::Address() { return &leaf_global; }
