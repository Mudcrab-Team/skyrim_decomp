// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10bf410, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10bf410 LeafAddress10bf410::Address
#include "LeafAddress10bf410.h"
extern unsigned char leaf_global;
void* LeafAddress10bf410::Address() { return &leaf_global; }
