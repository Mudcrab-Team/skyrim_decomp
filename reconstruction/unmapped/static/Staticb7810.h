// Source exposure: binary-analysis
// Staticb7810, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7810;
extern void construct(Staticb7810*, const Descriptor*);
extern void destroy(Staticb7810*);
struct Staticb7810 {
    void* value;
    Staticb7810() { construct(this, &descriptor); }
    ~Staticb7810() { destroy(this); }
};
