// Source exposure: binary-analysis
// Static103730, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103730;
extern void construct(Static103730*, const Descriptor*);
extern void destroy(Static103730*);
struct Static103730 {
    void* value;
    Static103730() { construct(this, &descriptor); }
    ~Static103730() { destroy(this); }
};
