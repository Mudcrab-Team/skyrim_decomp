// Source exposure: binary-analysis
// Staticde4f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticde4f0;
extern void construct(Staticde4f0*, const Descriptor*);
extern void destroy(Staticde4f0*);
struct Staticde4f0 {
    void* value;
    Staticde4f0() { construct(this, &descriptor); }
    ~Staticde4f0() { destroy(this); }
};
