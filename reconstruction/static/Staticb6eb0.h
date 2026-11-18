// Source exposure: binary-analysis
// Staticb6eb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6eb0;
extern void construct(Staticb6eb0*, const Descriptor*);
extern void destroy(Staticb6eb0*);
struct Staticb6eb0 {
    void* value;
    Staticb6eb0() { construct(this, &descriptor); }
    ~Staticb6eb0() { destroy(this); }
};
