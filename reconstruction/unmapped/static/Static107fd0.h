// Source exposure: binary-analysis
// Static107fd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static107fd0;
extern void construct(Static107fd0*, const Descriptor*);
extern void destroy(Static107fd0*);
struct Static107fd0 {
    void* value;
    Static107fd0() { construct(this, &descriptor); }
    ~Static107fd0() { destroy(this); }
};
