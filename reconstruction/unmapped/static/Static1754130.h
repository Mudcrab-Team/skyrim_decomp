// Source exposure: binary-analysis; no external implementation source reused.
// Static1754130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754130*);
    virtual void release(Static1754130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754130*);
struct Static1754130 {
    void* value;
    Static1754130();
    ~Static1754130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
