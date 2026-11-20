// Source exposure: binary-analysis; no external implementation source reused.
// Static177ad30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ad30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ad30*);
    virtual void release(Static177ad30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ad30*);
struct Static177ad30 {
    void* value;
    Static177ad30();
    ~Static177ad30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
