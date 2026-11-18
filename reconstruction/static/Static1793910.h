// Source exposure: binary-analysis; no external implementation source reused.
// Static1793910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793910*);
    virtual void release(Static1793910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793910*);
struct Static1793910 {
    void* value;
    Static1793910();
    ~Static1793910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
