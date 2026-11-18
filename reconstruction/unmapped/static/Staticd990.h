// Source exposure: binary-analysis
// Staticd990, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd990;
extern void construct(Staticd990*, const Descriptor*);
extern void destroy(Staticd990*);
struct Staticd990 {
    void* value;
    Staticd990() { construct(this, &descriptor); }
    ~Staticd990() { destroy(this); }
};
