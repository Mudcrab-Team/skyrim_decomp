// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49640, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49640 LeafAddressc49640::Address
#include "LeafAddressc49640.h"
extern unsigned char leaf_global;
void* LeafAddressc49640::Address() { return &leaf_global; }
