// Source exposure: binary-analysis; no external implementation source reused.
// Static174ab70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ab70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ab70*);
    virtual void release(Static174ab70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ab70*);
struct Static174ab70 {
    void* value;
    Static174ab70();
    ~Static174ab70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
