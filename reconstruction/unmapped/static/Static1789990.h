// Source exposure: binary-analysis; no external implementation source reused.
// Static1789990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789990*);
    virtual void release(Static1789990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789990*);
struct Static1789990 {
    void* value;
    Static1789990();
    ~Static1789990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
