// Source exposure: binary-analysis
// Staticefb20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefb20;
extern void construct(Staticefb20*, const Descriptor*);
extern void destroy(Staticefb20*);
struct Staticefb20 {
    void* value;
    Staticefb20() { construct(this, &descriptor); }
    ~Staticefb20() { destroy(this); }
};
