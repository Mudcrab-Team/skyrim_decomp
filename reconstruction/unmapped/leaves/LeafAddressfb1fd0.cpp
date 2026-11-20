// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb1fd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb1fd0 LeafAddressfb1fd0::Address
#include "LeafAddressfb1fd0.h"
extern unsigned char leaf_global;
void* LeafAddressfb1fd0::Address() { return &leaf_global; }
