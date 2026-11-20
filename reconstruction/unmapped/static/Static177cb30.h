// Source exposure: binary-analysis; no external implementation source reused.
// Static177cb30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cb30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cb30*);
    virtual void release(Static177cb30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cb30*);
struct Static177cb30 {
    void* value;
    Static177cb30();
    ~Static177cb30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
