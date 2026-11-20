// Source exposure: binary-analysis
// Statica0cf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0cf0;
extern void construct(Statica0cf0*, const Descriptor*);
extern void destroy(Statica0cf0*);
struct Statica0cf0 {
    void* value;
    Statica0cf0() { construct(this, &descriptor); }
    ~Statica0cf0() { destroy(this); }
};
