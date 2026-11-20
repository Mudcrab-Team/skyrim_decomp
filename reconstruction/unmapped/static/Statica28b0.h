// Source exposure: binary-analysis
// Statica28b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica28b0;
extern void construct(Statica28b0*, const Descriptor*);
extern void destroy(Statica28b0*);
struct Statica28b0 {
    void* value;
    Statica28b0() { construct(this, &descriptor); }
    ~Statica28b0() { destroy(this); }
};
