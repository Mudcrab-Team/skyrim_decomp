// Source exposure: binary-analysis
// Staticbdc50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdc50;
extern void construct(Staticbdc50*, const Descriptor*);
extern void destroy(Staticbdc50*);
struct Staticbdc50 {
    void* value;
    Staticbdc50() { construct(this, &descriptor); }
    ~Staticbdc50() { destroy(this); }
};
