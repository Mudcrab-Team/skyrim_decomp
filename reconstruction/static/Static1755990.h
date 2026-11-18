// Source exposure: binary-analysis; no external implementation source reused.
// Static1755990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755990*);
    virtual void release(Static1755990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755990*);
struct Static1755990 {
    void* value;
    Static1755990();
    ~Static1755990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
