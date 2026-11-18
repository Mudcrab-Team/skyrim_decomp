// Source exposure: binary-analysis
// Staticbdec0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdec0;
extern void construct(Staticbdec0*, const Descriptor*);
extern void destroy(Staticbdec0*);
struct Staticbdec0 {
    void* value;
    Staticbdec0() { construct(this, &descriptor); }
    ~Staticbdec0() { destroy(this); }
};
