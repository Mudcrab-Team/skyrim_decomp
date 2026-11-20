// Source exposure: binary-analysis
// Static103310, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103310;
extern void construct(Static103310*, const Descriptor*);
extern void destroy(Static103310*);
struct Static103310 {
    void* value;
    Static103310() { construct(this, &descriptor); }
    ~Static103310() { destroy(this); }
};
