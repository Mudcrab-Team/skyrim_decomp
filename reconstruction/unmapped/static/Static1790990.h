// Source exposure: binary-analysis; no external implementation source reused.
// Static1790990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790990*);
    virtual void release(Static1790990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790990*);
struct Static1790990 {
    void* value;
    Static1790990();
    ~Static1790990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
