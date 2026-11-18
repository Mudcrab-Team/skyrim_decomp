// Source exposure: binary-analysis
// Staticefa60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefa60;
extern void construct(Staticefa60*, const Descriptor*);
extern void destroy(Staticefa60*);
struct Staticefa60 {
    void* value;
    Staticefa60() { construct(this, &descriptor); }
    ~Staticefa60() { destroy(this); }
};
