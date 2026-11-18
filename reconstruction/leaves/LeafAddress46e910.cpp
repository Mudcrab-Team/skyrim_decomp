// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress46e910, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x46e910 LeafAddress46e910::Address
#include "LeafAddress46e910.h"
extern unsigned char leaf_global;
void* LeafAddress46e910::Address() { return &leaf_global; }
