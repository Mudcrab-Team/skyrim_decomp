// Source exposure: binary-analysis
// Staticbaf80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbaf80;
extern void construct(Staticbaf80*, const Descriptor*);
extern void destroy(Staticbaf80*);
struct Staticbaf80 {
    void* value;
    Staticbaf80() { construct(this, &descriptor); }
    ~Staticbaf80() { destroy(this); }
};
