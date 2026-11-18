// Source exposure: binary-analysis
// Static10a130, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a130;
extern void construct(Static10a130*, const Descriptor*);
extern void destroy(Static10a130*);
struct Static10a130 {
    void* value;
    Static10a130() { construct(this, &descriptor); }
    ~Static10a130() { destroy(this); }
};
