// Source exposure: binary-analysis
// Static8fbe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fbe0;
extern void construct(Static8fbe0*, const Descriptor*);
extern void destroy(Static8fbe0*);
struct Static8fbe0 {
    void* value;
    Static8fbe0() { construct(this, &descriptor); }
    ~Static8fbe0() { destroy(this); }
};
