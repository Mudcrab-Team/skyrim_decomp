// Source exposure: binary-analysis
// Statica2cf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2cf0;
extern void construct(Statica2cf0*, const Descriptor*);
extern void destroy(Statica2cf0*);
struct Statica2cf0 {
    void* value;
    Statica2cf0() { construct(this, &descriptor); }
    ~Statica2cf0() { destroy(this); }
};
