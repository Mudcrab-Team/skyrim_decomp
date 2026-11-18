// Source exposure: binary-analysis; no external implementation source reused.
// Static174ab20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ab20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ab20*);
    virtual void release(Static174ab20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ab20*);
struct Static174ab20 {
    void* value;
    Static174ab20();
    ~Static174ab20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
