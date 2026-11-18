// Source exposure: binary-analysis
// Staticca580, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca580;
extern void construct(Staticca580*, const Descriptor*);
extern void destroy(Staticca580*);
struct Staticca580 {
    void* value;
    Staticca580() { construct(this, &descriptor); }
    ~Staticca580() { destroy(this); }
};
