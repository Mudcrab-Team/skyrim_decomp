// Source exposure: binary-analysis; no external implementation source reused.
// Static1762320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762320*);
    virtual void release(Static1762320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762320*);
struct Static1762320 {
    void* value;
    Static1762320();
    ~Static1762320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
