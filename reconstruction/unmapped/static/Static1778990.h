// Source exposure: binary-analysis; no external implementation source reused.
// Static1778990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778990*);
    virtual void release(Static1778990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778990*);
struct Static1778990 {
    void* value;
    Static1778990();
    ~Static1778990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
