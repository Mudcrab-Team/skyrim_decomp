// Source exposure: binary-analysis
// Static8fc40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fc40;
extern void construct(Static8fc40*, const Descriptor*);
extern void destroy(Static8fc40*);
struct Static8fc40 {
    void* value;
    Static8fc40() { construct(this, &descriptor); }
    ~Static8fc40() { destroy(this); }
};
