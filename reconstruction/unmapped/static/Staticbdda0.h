// Source exposure: binary-analysis
// Staticbdda0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdda0;
extern void construct(Staticbdda0*, const Descriptor*);
extern void destroy(Staticbdda0*);
struct Staticbdda0 {
    void* value;
    Staticbdda0() { construct(this, &descriptor); }
    ~Staticbdda0() { destroy(this); }
};
