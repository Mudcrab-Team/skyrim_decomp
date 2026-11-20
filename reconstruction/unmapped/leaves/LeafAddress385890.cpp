// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress385890, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x385890 LeafAddress385890::Address
#include "LeafAddress385890.h"
extern unsigned char leaf_global;
void* LeafAddress385890::Address() { return &leaf_global; }
