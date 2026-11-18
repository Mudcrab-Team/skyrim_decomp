// Source exposure: binary-analysis
// Staticf06b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf06b0;
extern void construct(Staticf06b0*, const Descriptor*);
extern void destroy(Staticf06b0*);
struct Staticf06b0 {
    void* value;
    Staticf06b0() { construct(this, &descriptor); }
    ~Staticf06b0() { destroy(this); }
};
