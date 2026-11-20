// Source exposure: binary-analysis; no external implementation source reused.
// Static1758500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758500*);
    virtual void release(Static1758500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758500*);
struct Static1758500 {
    void* value;
    Static1758500();
    ~Static1758500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
