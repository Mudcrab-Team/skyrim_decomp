// Source exposure: binary-analysis
// Statica0cc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0cc0;
extern void construct(Statica0cc0*, const Descriptor*);
extern void destroy(Statica0cc0*);
struct Statica0cc0 {
    void* value;
    Statica0cc0() { construct(this, &descriptor); }
    ~Statica0cc0() { destroy(this); }
};
