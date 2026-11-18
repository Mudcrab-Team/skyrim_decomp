// Source exposure: binary-analysis
// Staticbda80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbda80;
extern void construct(Staticbda80*, const Descriptor*);
extern void destroy(Staticbda80*);
struct Staticbda80 {
    void* value;
    Staticbda80() { construct(this, &descriptor); }
    ~Staticbda80() { destroy(this); }
};
