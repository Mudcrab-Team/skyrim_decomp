// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress129b440, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x129b440 LeafAddress129b440::Address
#include "LeafAddress129b440.h"
extern unsigned char leaf_global;
void* LeafAddress129b440::Address() { return &leaf_global; }
