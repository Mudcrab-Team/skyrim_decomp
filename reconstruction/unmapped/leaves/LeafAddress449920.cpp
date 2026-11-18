// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress449920, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x449920 LeafAddress449920::Address
#include "LeafAddress449920.h"
extern unsigned char leaf_global;
void* LeafAddress449920::Address() { return &leaf_global; }
