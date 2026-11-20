// Source exposure: binary-analysis
// Statica2be0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2be0;
extern void construct(Statica2be0*, const Descriptor*);
extern void destroy(Statica2be0*);
struct Statica2be0 {
    void* value;
    Statica2be0() { construct(this, &descriptor); }
    ~Statica2be0() { destroy(this); }
};
