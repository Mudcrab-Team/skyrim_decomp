// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5fe280, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5fe280 LeafAddress5fe280::Address
#include "LeafAddress5fe280.h"
extern unsigned char leaf_global;
void* LeafAddress5fe280::Address() { return &leaf_global; }
