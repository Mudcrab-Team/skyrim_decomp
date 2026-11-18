// Source exposure: binary-analysis
// Static108090, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108090;
extern void construct(Static108090*, const Descriptor*);
extern void destroy(Static108090*);
struct Static108090 {
    void* value;
    Static108090() { construct(this, &descriptor); }
    ~Static108090() { destroy(this); }
};
