// Source exposure: binary-analysis
// Staticbddd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbddd0;
extern void construct(Staticbddd0*, const Descriptor*);
extern void destroy(Staticbddd0*);
struct Staticbddd0 {
    void* value;
    Staticbddd0() { construct(this, &descriptor); }
    ~Staticbddd0() { destroy(this); }
};
