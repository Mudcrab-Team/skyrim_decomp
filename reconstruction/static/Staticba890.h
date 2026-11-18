// Source exposure: binary-analysis
// Staticba890, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticba890;
extern void construct(Staticba890*, const Descriptor*);
extern void destroy(Staticba890*);
struct Staticba890 {
    void* value;
    Staticba890() { construct(this, &descriptor); }
    ~Staticba890() { destroy(this); }
};
