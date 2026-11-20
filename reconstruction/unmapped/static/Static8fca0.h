// Source exposure: binary-analysis
// Static8fca0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fca0;
extern void construct(Static8fca0*, const Descriptor*);
extern void destroy(Static8fca0*);
struct Static8fca0 {
    void* value;
    Static8fca0() { construct(this, &descriptor); }
    ~Static8fca0() { destroy(this); }
};
