// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress46d450, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x46d450 LeafAddress46d450::Address
#include "LeafAddress46d450.h"
extern unsigned char leaf_global;
void* LeafAddress46d450::Address() { return &leaf_global; }
