// Source exposure: binary-analysis
// Staticba830, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticba830;
extern void construct(Staticba830*, const Descriptor*);
extern void destroy(Staticba830*);
struct Staticba830 {
    void* value;
    Staticba830() { construct(this, &descriptor); }
    ~Staticba830() { destroy(this); }
};
