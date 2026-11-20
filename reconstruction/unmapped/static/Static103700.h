// Source exposure: binary-analysis
// Static103700, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103700;
extern void construct(Static103700*, const Descriptor*);
extern void destroy(Static103700*);
struct Static103700 {
    void* value;
    Static103700() { construct(this, &descriptor); }
    ~Static103700() { destroy(this); }
};
