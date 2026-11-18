// Source exposure: binary-analysis
// Static10a340, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a340;
extern void construct(Static10a340*, const Descriptor*);
extern void destroy(Static10a340*);
struct Static10a340 {
    void* value;
    Static10a340() { construct(this, &descriptor); }
    ~Static10a340() { destroy(this); }
};
