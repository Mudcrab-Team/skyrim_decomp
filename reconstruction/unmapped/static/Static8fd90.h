// Source exposure: binary-analysis
// Static8fd90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fd90;
extern void construct(Static8fd90*, const Descriptor*);
extern void destroy(Static8fd90*);
struct Static8fd90 {
    void* value;
    Static8fd90() { construct(this, &descriptor); }
    ~Static8fd90() { destroy(this); }
};
