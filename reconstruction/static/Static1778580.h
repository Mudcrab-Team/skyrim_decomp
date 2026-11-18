// Source exposure: binary-analysis; no external implementation source reused.
// Static1778580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778580*);
    virtual void release(Static1778580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778580*);
struct Static1778580 {
    void* value;
    Static1778580();
    ~Static1778580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
