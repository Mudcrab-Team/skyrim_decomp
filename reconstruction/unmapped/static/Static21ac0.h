// Source exposure: binary-analysis
// Static21ac0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21ac0;
extern void construct(Static21ac0*, const Descriptor*);
extern void destroy(Static21ac0*);
struct Static21ac0 {
    void* value;
    Static21ac0() { construct(this, &descriptor); }
    ~Static21ac0() { destroy(this); }
};
