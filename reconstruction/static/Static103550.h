// Source exposure: binary-analysis
// Static103550, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103550;
extern void construct(Static103550*, const Descriptor*);
extern void destroy(Static103550*);
struct Static103550 {
    void* value;
    Static103550() { construct(this, &descriptor); }
    ~Static103550() { destroy(this); }
};
