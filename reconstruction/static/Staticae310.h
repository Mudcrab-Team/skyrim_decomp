// Source exposure: binary-analysis
// Staticae310, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticae310;
extern void construct(Staticae310*, const Descriptor*);
extern void destroy(Staticae310*);
struct Staticae310 {
    void* value;
    Staticae310() { construct(this, &descriptor); }
    ~Staticae310() { destroy(this); }
};
