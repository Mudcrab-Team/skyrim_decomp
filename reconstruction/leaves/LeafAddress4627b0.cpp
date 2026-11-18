// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4627b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4627b0 LeafAddress4627b0::Address
#include "LeafAddress4627b0.h"
extern unsigned char leaf_global;
void* LeafAddress4627b0::Address() { return &leaf_global; }
