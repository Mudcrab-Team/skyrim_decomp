// Source exposure: binary-analysis
// Static103130, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103130;
extern void construct(Static103130*, const Descriptor*);
extern void destroy(Static103130*);
struct Static103130 {
    void* value;
    Static103130() { construct(this, &descriptor); }
    ~Static103130() { destroy(this); }
};
