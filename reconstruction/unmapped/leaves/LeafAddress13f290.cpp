// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress13f290, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x13f290 LeafAddress13f290::Address
#include "LeafAddress13f290.h"
extern unsigned char leaf_global;
void* LeafAddress13f290::Address() { return &leaf_global; }
