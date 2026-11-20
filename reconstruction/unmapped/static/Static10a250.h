// Source exposure: binary-analysis
// Static10a250, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a250;
extern void construct(Static10a250*, const Descriptor*);
extern void destroy(Static10a250*);
struct Static10a250 {
    void* value;
    Static10a250() { construct(this, &descriptor); }
    ~Static10a250() { destroy(this); }
};
