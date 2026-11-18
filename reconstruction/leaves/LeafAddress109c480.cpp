// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress109c480, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x109c480 LeafAddress109c480::Address
#include "LeafAddress109c480.h"
extern unsigned char leaf_global;
void* LeafAddress109c480::Address() { return &leaf_global; }
