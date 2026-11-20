// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress487f80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x487f80 LeafAddress487f80::Address
#include "LeafAddress487f80.h"
extern unsigned char leaf_global;
void* LeafAddress487f80::Address() { return &leaf_global; }
