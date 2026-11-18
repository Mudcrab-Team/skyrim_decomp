// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress57e910, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x57e910 LeafAddress57e910::Address
#include "LeafAddress57e910.h"
extern unsigned char leaf_global;
void* LeafAddress57e910::Address() { return &leaf_global; }
