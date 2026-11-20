// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1f5030, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1f5030 LeafAddress1f5030::Address
#include "LeafAddress1f5030.h"
extern unsigned char leaf_global;
void* LeafAddress1f5030::Address() { return &leaf_global; }
