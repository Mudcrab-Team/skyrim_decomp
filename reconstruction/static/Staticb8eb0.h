// Source exposure: binary-analysis
// Staticb8eb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8eb0;
extern void construct(Staticb8eb0*, const Descriptor*);
extern void destroy(Staticb8eb0*);
struct Staticb8eb0 {
    void* value;
    Staticb8eb0() { construct(this, &descriptor); }
    ~Staticb8eb0() { destroy(this); }
};
