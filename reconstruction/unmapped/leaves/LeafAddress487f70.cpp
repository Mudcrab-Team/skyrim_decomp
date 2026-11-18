// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress487f70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x487f70 LeafAddress487f70::Address
#include "LeafAddress487f70.h"
extern unsigned char leaf_global;
void* LeafAddress487f70::Address() { return &leaf_global; }
