// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress46e920, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x46e920 LeafAddress46e920::Address
#include "LeafAddress46e920.h"
extern unsigned char leaf_global;
void* LeafAddress46e920::Address() { return &leaf_global; }
