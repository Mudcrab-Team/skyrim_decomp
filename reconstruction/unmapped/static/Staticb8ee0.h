// Source exposure: binary-analysis
// Staticb8ee0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8ee0;
extern void construct(Staticb8ee0*, const Descriptor*);
extern void destroy(Staticb8ee0*);
struct Staticb8ee0 {
    void* value;
    Staticb8ee0() { construct(this, &descriptor); }
    ~Staticb8ee0() { destroy(this); }
};
