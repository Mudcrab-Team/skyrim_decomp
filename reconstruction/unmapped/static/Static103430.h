// Source exposure: binary-analysis
// Static103430, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103430;
extern void construct(Static103430*, const Descriptor*);
extern void destroy(Static103430*);
struct Static103430 {
    void* value;
    Static103430() { construct(this, &descriptor); }
    ~Static103430() { destroy(this); }
};
