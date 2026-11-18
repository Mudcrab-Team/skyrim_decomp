// Source exposure: binary-analysis
// Staticca040, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca040;
extern void construct(Staticca040*, const Descriptor*);
extern void destroy(Staticca040*);
struct Staticca040 {
    void* value;
    Staticca040() { construct(this, &descriptor); }
    ~Staticca040() { destroy(this); }
};
