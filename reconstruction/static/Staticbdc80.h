// Source exposure: binary-analysis
// Staticbdc80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdc80;
extern void construct(Staticbdc80*, const Descriptor*);
extern void destroy(Staticbdc80*);
struct Staticbdc80 {
    void* value;
    Staticbdc80() { construct(this, &descriptor); }
    ~Staticbdc80() { destroy(this); }
};
