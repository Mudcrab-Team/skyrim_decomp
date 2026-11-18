// Source exposure: binary-analysis
// Static8fdc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fdc0;
extern void construct(Static8fdc0*, const Descriptor*);
extern void destroy(Static8fdc0*);
struct Static8fdc0 {
    void* value;
    Static8fdc0() { construct(this, &descriptor); }
    ~Static8fdc0() { destroy(this); }
};
