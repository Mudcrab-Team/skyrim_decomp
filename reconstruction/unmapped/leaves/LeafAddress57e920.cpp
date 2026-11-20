// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress57e920, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x57e920 LeafAddress57e920::Address
#include "LeafAddress57e920.h"
extern unsigned char leaf_global;
void* LeafAddress57e920::Address() { return &leaf_global; }
