// Source exposure: binary-analysis
// Static8b540, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b540;
extern void construct(Static8b540*, const Descriptor*);
extern void destroy(Static8b540*);
struct Static8b540 {
    void* value;
    Static8b540() { construct(this, &descriptor); }
    ~Static8b540() { destroy(this); }
};
