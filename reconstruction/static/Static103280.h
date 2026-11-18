// Source exposure: binary-analysis
// Static103280, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103280;
extern void construct(Static103280*, const Descriptor*);
extern void destroy(Static103280*);
struct Static103280 {
    void* value;
    Static103280() { construct(this, &descriptor); }
    ~Static103280() { destroy(this); }
};
