// Source exposure: binary-analysis
// Staticf2990, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf2990;
extern void construct(Staticf2990*, const Descriptor*);
extern void destroy(Staticf2990*);
struct Staticf2990 {
    void* value;
    Staticf2990() { construct(this, &descriptor); }
    ~Staticf2990() { destroy(this); }
};
