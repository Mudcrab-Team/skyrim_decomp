// Source exposure: binary-analysis
// Staticde4c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticde4c0;
extern void construct(Staticde4c0*, const Descriptor*);
extern void destroy(Staticde4c0*);
struct Staticde4c0 {
    void* value;
    Staticde4c0() { construct(this, &descriptor); }
    ~Staticde4c0() { destroy(this); }
};
