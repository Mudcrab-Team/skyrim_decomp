// Source exposure: binary-analysis
// Staticb65f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb65f0;
extern void construct(Staticb65f0*, const Descriptor*);
extern void destroy(Staticb65f0*);
struct Staticb65f0 {
    void* value;
    Staticb65f0() { construct(this, &descriptor); }
    ~Staticb65f0() { destroy(this); }
};
