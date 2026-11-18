// Source exposure: binary-analysis
// Statica43b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica43b0;
extern void construct(Statica43b0*, const Descriptor*);
extern void destroy(Statica43b0*);
struct Statica43b0 {
    void* value;
    Statica43b0() { construct(this, &descriptor); }
    ~Statica43b0() { destroy(this); }
};
