// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa380*);
    virtual void release(Static17aa380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa380*);
struct Static17aa380 {
    void* value;
    Static17aa380();
    ~Static17aa380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
