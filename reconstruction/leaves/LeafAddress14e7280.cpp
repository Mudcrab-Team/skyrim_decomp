// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress14e7280, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x14e7280 LeafAddress14e7280::Address
#include "LeafAddress14e7280.h"
extern unsigned char leaf_global;
void* LeafAddress14e7280::Address() { return &leaf_global; }
