// Source exposure: binary-analysis; no external implementation source reused.
// Static175bed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bed0*);
    virtual void release(Static175bed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bed0*);
struct Static175bed0 {
    void* value;
    Static175bed0();
    ~Static175bed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
