// Source exposure: binary-analysis
// Statica0ba0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0ba0;
extern void construct(Statica0ba0*, const Descriptor*);
extern void destroy(Statica0ba0*);
struct Statica0ba0 {
    void* value;
    Statica0ba0() { construct(this, &descriptor); }
    ~Statica0ba0() { destroy(this); }
};
