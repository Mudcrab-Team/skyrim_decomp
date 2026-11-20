// Source exposure: binary-analysis; no external implementation source reused.
// Static17b3f00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b3f00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b3f00*);
    virtual void release(Static17b3f00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b3f00*);
struct Static17b3f00 {
    void* value;
    Static17b3f00();
    ~Static17b3f00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
