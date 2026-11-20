// Source exposure: binary-analysis; no external implementation source reused.
// Static1753190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753190*);
    virtual void release(Static1753190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753190*);
struct Static1753190 {
    void* value;
    Static1753190();
    ~Static1753190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
