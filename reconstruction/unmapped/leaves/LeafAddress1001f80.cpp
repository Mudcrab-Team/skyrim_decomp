// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1001f80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1001f80 LeafAddress1001f80::Address
#include "LeafAddress1001f80.h"
extern unsigned char leaf_global;
void* LeafAddress1001f80::Address() { return &leaf_global; }
