// Source exposure: binary-analysis
// Static8fa60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fa60;
extern void construct(Static8fa60*, const Descriptor*);
extern void destroy(Static8fa60*);
struct Static8fa60 {
    void* value;
    Static8fa60() { construct(this, &descriptor); }
    ~Static8fa60() { destroy(this); }
};
