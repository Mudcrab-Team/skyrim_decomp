// Source exposure: binary-analysis; no external implementation source reused.
// Static1760020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760020*);
    virtual void release(Static1760020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760020*);
struct Static1760020 {
    void* value;
    Static1760020();
    ~Static1760020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
