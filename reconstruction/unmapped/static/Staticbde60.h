// Source exposure: binary-analysis
// Staticbde60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbde60;
extern void construct(Staticbde60*, const Descriptor*);
extern void destroy(Staticbde60*);
struct Staticbde60 {
    void* value;
    Staticbde60() { construct(this, &descriptor); }
    ~Staticbde60() { destroy(this); }
};
