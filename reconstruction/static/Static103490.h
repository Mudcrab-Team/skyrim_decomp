// Source exposure: binary-analysis
// Static103490, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103490;
extern void construct(Static103490*, const Descriptor*);
extern void destroy(Static103490*);
struct Static103490 {
    void* value;
    Static103490() { construct(this, &descriptor); }
    ~Static103490() { destroy(this); }
};
