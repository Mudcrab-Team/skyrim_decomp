// Source exposure: binary-analysis
// Staticac190, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticac190;
extern void construct(Staticac190*, const Descriptor*);
extern void destroy(Staticac190*);
struct Staticac190 {
    void* value;
    Staticac190() { construct(this, &descriptor); }
    ~Staticac190() { destroy(this); }
};
