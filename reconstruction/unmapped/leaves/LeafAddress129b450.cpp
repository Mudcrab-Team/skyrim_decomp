// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress129b450, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x129b450 LeafAddress129b450::Address
#include "LeafAddress129b450.h"
extern unsigned char leaf_global;
void* LeafAddress129b450::Address() { return &leaf_global; }
