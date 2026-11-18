// Source exposure: binary-analysis
// Staticbdc20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdc20;
extern void construct(Staticbdc20*, const Descriptor*);
extern void destroy(Staticbdc20*);
struct Staticbdc20 {
    void* value;
    Staticbdc20() { construct(this, &descriptor); }
    ~Staticbdc20() { destroy(this); }
};
