// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress48edd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x48edd0 LeafAddress48edd0::Address
#include "LeafAddress48edd0.h"
extern unsigned char leaf_global;
void* LeafAddress48edd0::Address() { return &leaf_global; }
