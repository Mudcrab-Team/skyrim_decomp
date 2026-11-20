// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress7f5380, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x7f5380 LeafAddress7f5380::Address
#include "LeafAddress7f5380.h"
extern unsigned char leaf_global;
void* LeafAddress7f5380::Address() { return &leaf_global; }
