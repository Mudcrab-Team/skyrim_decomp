// Source exposure: binary-analysis
// Staticbde30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbde30;
extern void construct(Staticbde30*, const Descriptor*);
extern void destroy(Staticbde30*);
struct Staticbde30 {
    void* value;
    Staticbde30() { construct(this, &descriptor); }
    ~Staticbde30() { destroy(this); }
};
