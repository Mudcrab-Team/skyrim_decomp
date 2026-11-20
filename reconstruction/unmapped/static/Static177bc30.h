// Source exposure: binary-analysis; no external implementation source reused.
// Static177bc30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bc30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bc30*);
    virtual void release(Static177bc30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bc30*);
struct Static177bc30 {
    void* value;
    Static177bc30();
    ~Static177bc30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
