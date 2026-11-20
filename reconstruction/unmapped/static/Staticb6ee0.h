// Source exposure: binary-analysis
// Staticb6ee0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6ee0;
extern void construct(Staticb6ee0*, const Descriptor*);
extern void destroy(Staticb6ee0*);
struct Staticb6ee0 {
    void* value;
    Staticb6ee0() { construct(this, &descriptor); }
    ~Staticb6ee0() { destroy(this); }
};
