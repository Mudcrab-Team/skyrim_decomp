// Source exposure: binary-analysis
// Statica2af0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2af0;
extern void construct(Statica2af0*, const Descriptor*);
extern void destroy(Statica2af0*);
struct Statica2af0 {
    void* value;
    Statica2af0() { construct(this, &descriptor); }
    ~Statica2af0() { destroy(this); }
};
