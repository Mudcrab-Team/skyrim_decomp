// Source exposure: binary-analysis; no external implementation source reused.
// Static1777400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777400*);
    virtual void release(Static1777400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777400*);
struct Static1777400 {
    void* value;
    Static1777400();
    ~Static1777400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
