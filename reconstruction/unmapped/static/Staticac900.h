// Source exposure: binary-analysis
// Staticac900, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticac900;
extern void construct(Staticac900*, const Descriptor*);
extern void destroy(Staticac900*);
struct Staticac900 {
    void* value;
    Staticac900() { construct(this, &descriptor); }
    ~Staticac900() { destroy(this); }
};
