// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5ae720, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5ae720 LeafAddress5ae720::Address
#include "LeafAddress5ae720.h"
extern unsigned char leaf_global;
void* LeafAddress5ae720::Address() { return &leaf_global; }
