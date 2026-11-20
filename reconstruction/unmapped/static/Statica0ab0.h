// Source exposure: binary-analysis
// Statica0ab0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0ab0;
extern void construct(Statica0ab0*, const Descriptor*);
extern void destroy(Statica0ab0*);
struct Statica0ab0 {
    void* value;
    Statica0ab0() { construct(this, &descriptor); }
    ~Statica0ab0() { destroy(this); }
};
