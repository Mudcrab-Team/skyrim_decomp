// Source exposure: binary-analysis
// Static103250, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103250;
extern void construct(Static103250*, const Descriptor*);
extern void destroy(Static103250*);
struct Static103250 {
    void* value;
    Static103250() { construct(this, &descriptor); }
    ~Static103250() { destroy(this); }
};
