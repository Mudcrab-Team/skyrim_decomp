// Source exposure: binary-analysis; no external implementation source reused.
// Static1797990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1797990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1797990*);
    virtual void release(Static1797990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1797990*);
struct Static1797990 {
    void* value;
    Static1797990();
    ~Static1797990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
