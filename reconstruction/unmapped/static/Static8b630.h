// Source exposure: binary-analysis
// Static8b630, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b630;
extern void construct(Static8b630*, const Descriptor*);
extern void destroy(Static8b630*);
struct Static8b630 {
    void* value;
    Static8b630() { construct(this, &descriptor); }
    ~Static8b630() { destroy(this); }
};
