// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1104030, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1104030 LeafAddress1104030::Address
#include "LeafAddress1104030.h"
extern unsigned char leaf_global;
void* LeafAddress1104030::Address() { return &leaf_global; }
