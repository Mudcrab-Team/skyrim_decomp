// Source exposure: binary-analysis; no external implementation source reused.
// Static1760070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760070*);
    virtual void release(Static1760070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760070*);
struct Static1760070 {
    void* value;
    Static1760070();
    ~Static1760070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
