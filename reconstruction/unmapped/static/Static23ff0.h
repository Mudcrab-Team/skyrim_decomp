// Source exposure: binary-analysis
// Static23ff0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23ff0;
extern void construct(Static23ff0*, const Descriptor*);
extern void destroy(Static23ff0*);
struct Static23ff0 {
    void* value;
    Static23ff0() { construct(this, &descriptor); }
    ~Static23ff0() { destroy(this); }
};
