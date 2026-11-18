// Source exposure: binary-analysis
// Staticb1fb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb1fb0;
extern void construct(Staticb1fb0*, const Descriptor*);
extern void destroy(Staticb1fb0*);
struct Staticb1fb0 {
    void* value;
    Staticb1fb0() { construct(this, &descriptor); }
    ~Staticb1fb0() { destroy(this); }
};
