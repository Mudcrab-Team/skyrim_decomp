// Source exposure: binary-analysis; no external implementation source reused.
// Static17b3e10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b3e10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b3e10*);
    virtual void release(Static17b3e10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b3e10*);
struct Static17b3e10 {
    void* value;
    Static17b3e10();
    ~Static17b3e10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
