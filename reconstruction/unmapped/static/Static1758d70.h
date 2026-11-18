// Source exposure: binary-analysis; no external implementation source reused.
// Static1758d70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758d70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758d70*);
    virtual void release(Static1758d70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758d70*);
struct Static1758d70 {
    void* value;
    Static1758d70();
    ~Static1758d70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
