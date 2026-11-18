// Source exposure: binary-analysis
// Staticbaf50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbaf50;
extern void construct(Staticbaf50*, const Descriptor*);
extern void destroy(Staticbaf50*);
struct Staticbaf50 {
    void* value;
    Staticbaf50() { construct(this, &descriptor); }
    ~Staticbaf50() { destroy(this); }
};
