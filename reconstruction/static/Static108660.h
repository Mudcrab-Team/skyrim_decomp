// Source exposure: binary-analysis
// Static108660, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108660;
extern void construct(Static108660*, const Descriptor*);
extern void destroy(Static108660*);
struct Static108660 {
    void* value;
    Static108660() { construct(this, &descriptor); }
    ~Static108660() { destroy(this); }
};
