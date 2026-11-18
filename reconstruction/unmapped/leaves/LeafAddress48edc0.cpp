// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress48edc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x48edc0 LeafAddress48edc0::Address
#include "LeafAddress48edc0.h"
extern unsigned char leaf_global;
void* LeafAddress48edc0::Address() { return &leaf_global; }
