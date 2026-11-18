// Source exposure: binary-analysis
// Static8afa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8afa0;
extern void construct(Static8afa0*, const Descriptor*);
extern void destroy(Static8afa0*);
struct Static8afa0 {
    void* value;
    Static8afa0() { construct(this, &descriptor); }
    ~Static8afa0() { destroy(this); }
};
