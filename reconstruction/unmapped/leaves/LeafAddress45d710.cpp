// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45d710, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45d710 LeafAddress45d710::Address
#include "LeafAddress45d710.h"
extern unsigned char leaf_global;
void* LeafAddress45d710::Address() { return &leaf_global; }
