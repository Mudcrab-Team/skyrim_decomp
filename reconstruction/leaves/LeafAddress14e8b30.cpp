// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress14e8b30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x14e8b30 LeafAddress14e8b30::Address
#include "LeafAddress14e8b30.h"
extern unsigned char leaf_global;
void* LeafAddress14e8b30::Address() { return &leaf_global; }
