// Source exposure: binary-analysis
// Statica7ac0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica7ac0;
extern void construct(Statica7ac0*, const Descriptor*);
extern void destroy(Statica7ac0*);
struct Statica7ac0 {
    void* value;
    Statica7ac0() { construct(this, &descriptor); }
    ~Statica7ac0() { destroy(this); }
};
