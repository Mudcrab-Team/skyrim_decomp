// Source exposure: binary-analysis; no external implementation source reused.
// Static177add0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177add0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177add0*);
    virtual void release(Static177add0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177add0*);
struct Static177add0 {
    void* value;
    Static177add0();
    ~Static177add0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
