// Source exposure: binary-analysis
// Staticb4bc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4bc0;
extern void construct(Staticb4bc0*, const Descriptor*);
extern void destroy(Staticb4bc0*);
struct Staticb4bc0 {
    void* value;
    Staticb4bc0() { construct(this, &descriptor); }
    ~Staticb4bc0() { destroy(this); }
};
