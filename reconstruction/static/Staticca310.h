// Source exposure: binary-analysis
// Staticca310, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca310;
extern void construct(Staticca310*, const Descriptor*);
extern void destroy(Staticca310*);
struct Staticca310 {
    void* value;
    Staticca310() { construct(this, &descriptor); }
    ~Staticca310() { destroy(this); }
};
