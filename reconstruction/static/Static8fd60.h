// Source exposure: binary-analysis
// Static8fd60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fd60;
extern void construct(Static8fd60*, const Descriptor*);
extern void destroy(Static8fd60*);
struct Static8fd60 {
    void* value;
    Static8fd60() { construct(this, &descriptor); }
    ~Static8fd60() { destroy(this); }
};
