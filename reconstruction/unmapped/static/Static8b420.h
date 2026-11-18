// Source exposure: binary-analysis
// Static8b420, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b420;
extern void construct(Static8b420*, const Descriptor*);
extern void destroy(Static8b420*);
struct Static8b420 {
    void* value;
    Static8b420() { construct(this, &descriptor); }
    ~Static8b420() { destroy(this); }
};
