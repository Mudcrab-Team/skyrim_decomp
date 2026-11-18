// Source exposure: binary-analysis
// Staticb6c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6c0;
extern void construct(Staticb6c0*, const Descriptor*);
extern void destroy(Staticb6c0*);
struct Staticb6c0 {
    void* value;
    Staticb6c0() { construct(this, &descriptor); }
    ~Staticb6c0() { destroy(this); }
};
