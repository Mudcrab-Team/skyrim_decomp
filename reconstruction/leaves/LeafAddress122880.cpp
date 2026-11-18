// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress122880, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x122880 LeafAddress122880::Address
#include "LeafAddress122880.h"
extern unsigned char leaf_global;
void* LeafAddress122880::Address() { return &leaf_global; }
