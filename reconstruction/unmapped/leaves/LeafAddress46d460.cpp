// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress46d460, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x46d460 LeafAddress46d460::Address
#include "LeafAddress46d460.h"
extern unsigned char leaf_global;
void* LeafAddress46d460::Address() { return &leaf_global; }
