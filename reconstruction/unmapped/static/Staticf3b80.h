// Source exposure: binary-analysis
// Staticf3b80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf3b80;
extern void construct(Staticf3b80*, const Descriptor*);
extern void destroy(Staticf3b80*);
struct Staticf3b80 {
    void* value;
    Staticf3b80() { construct(this, &descriptor); }
    ~Staticf3b80() { destroy(this); }
};
