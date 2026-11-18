// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10af740, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10af740 LeafAddress10af740::Address
#include "LeafAddress10af740.h"
extern unsigned char leaf_global;
void* LeafAddress10af740::Address() { return &leaf_global; }
