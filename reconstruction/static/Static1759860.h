// Source exposure: binary-analysis; no external implementation source reused.
// Static1759860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759860*);
    virtual void release(Static1759860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759860*);
struct Static1759860 {
    void* value;
    Static1759860();
    ~Static1759860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
