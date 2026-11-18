// Source exposure: binary-analysis
// Staticca070, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca070;
extern void construct(Staticca070*, const Descriptor*);
extern void destroy(Staticca070*);
struct Staticca070 {
    void* value;
    Staticca070() { construct(this, &descriptor); }
    ~Staticca070() { destroy(this); }
};
