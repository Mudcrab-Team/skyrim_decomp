// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc3d880, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc3d880 LeafAddressc3d880::Address
#include "LeafAddressc3d880.h"
extern unsigned char leaf_global;
void* LeafAddressc3d880::Address() { return &leaf_global; }
