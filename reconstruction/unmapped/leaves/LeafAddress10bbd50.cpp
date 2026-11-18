// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10bbd50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10bbd50 LeafAddress10bbd50::Address
#include "LeafAddress10bbd50.h"
extern unsigned char leaf_global;
void* LeafAddress10bbd50::Address() { return &leaf_global; }
