// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress146710, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x146710 LeafAddress146710::Address
#include "LeafAddress146710.h"
extern unsigned char leaf_global;
void* LeafAddress146710::Address() { return &leaf_global; }
