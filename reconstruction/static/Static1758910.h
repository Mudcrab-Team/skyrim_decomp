// Source exposure: binary-analysis; no external implementation source reused.
// Static1758910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758910*);
    virtual void release(Static1758910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758910*);
struct Static1758910 {
    void* value;
    Static1758910();
    ~Static1758910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
