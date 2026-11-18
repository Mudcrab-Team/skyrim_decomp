// Source exposure: binary-analysis
// Staticbde00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbde00;
extern void construct(Staticbde00*, const Descriptor*);
extern void destroy(Staticbde00*);
struct Staticbde00 {
    void* value;
    Staticbde00() { construct(this, &descriptor); }
    ~Staticbde00() { destroy(this); }
};
