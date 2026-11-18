// Source exposure: binary-analysis
// Statica0ae0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0ae0;
extern void construct(Statica0ae0*, const Descriptor*);
extern void destroy(Statica0ae0*);
struct Statica0ae0 {
    void* value;
    Statica0ae0() { construct(this, &descriptor); }
    ~Statica0ae0() { destroy(this); }
};
