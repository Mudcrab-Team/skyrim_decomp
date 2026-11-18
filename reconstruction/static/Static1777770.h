// Source exposure: binary-analysis; no external implementation source reused.
// Static1777770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777770*);
    virtual void release(Static1777770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777770*);
struct Static1777770 {
    void* value;
    Static1777770();
    ~Static1777770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
