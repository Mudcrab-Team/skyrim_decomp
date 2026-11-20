// Source exposure: binary-analysis; no external implementation source reused.
// Static1754400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754400*);
    virtual void release(Static1754400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754400*);
struct Static1754400 {
    void* value;
    Static1754400();
    ~Static1754400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
