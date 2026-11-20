// Source exposure: binary-analysis
// Staticb6fa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6fa0;
extern void construct(Staticb6fa0*, const Descriptor*);
extern void destroy(Staticb6fa0*);
struct Staticb6fa0 {
    void* value;
    Staticb6fa0() { construct(this, &descriptor); }
    ~Staticb6fa0() { destroy(this); }
};
