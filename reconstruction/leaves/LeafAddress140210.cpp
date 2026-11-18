// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress140210, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x140210 LeafAddress140210::Address
#include "LeafAddress140210.h"
extern unsigned char leaf_global;
void* LeafAddress140210::Address() { return &leaf_global; }
