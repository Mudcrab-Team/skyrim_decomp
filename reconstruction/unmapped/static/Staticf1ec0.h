// Source exposure: binary-analysis
// Staticf1ec0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf1ec0;
extern void construct(Staticf1ec0*, const Descriptor*);
extern void destroy(Staticf1ec0*);
struct Staticf1ec0 {
    void* value;
    Staticf1ec0() { construct(this, &descriptor); }
    ~Staticf1ec0() { destroy(this); }
};
