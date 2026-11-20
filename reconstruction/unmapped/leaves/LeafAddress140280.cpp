// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress140280, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x140280 LeafAddress140280::Address
#include "LeafAddress140280.h"
extern unsigned char leaf_global;
void* LeafAddress140280::Address() { return &leaf_global; }
