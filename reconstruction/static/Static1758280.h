// Source exposure: binary-analysis; no external implementation source reused.
// Static1758280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758280*);
    virtual void release(Static1758280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758280*);
struct Static1758280 {
    void* value;
    Static1758280();
    ~Static1758280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
