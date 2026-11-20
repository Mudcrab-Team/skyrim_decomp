// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1570d30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1570d30 LeafAddress1570d30::Address
#include "LeafAddress1570d30.h"
extern unsigned char leaf_global;
void* LeafAddress1570d30::Address() { return &leaf_global; }
