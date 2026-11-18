// Source exposure: binary-analysis
// Staticefe80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefe80;
extern void construct(Staticefe80*, const Descriptor*);
extern void destroy(Staticefe80*);
struct Staticefe80 {
    void* value;
    Staticefe80() { construct(this, &descriptor); }
    ~Staticefe80() { destroy(this); }
};
