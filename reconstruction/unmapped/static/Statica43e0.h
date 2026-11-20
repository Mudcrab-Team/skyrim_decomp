// Source exposure: binary-analysis
// Statica43e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica43e0;
extern void construct(Statica43e0*, const Descriptor*);
extern void destroy(Statica43e0*);
struct Statica43e0 {
    void* value;
    Statica43e0() { construct(this, &descriptor); }
    ~Statica43e0() { destroy(this); }
};
