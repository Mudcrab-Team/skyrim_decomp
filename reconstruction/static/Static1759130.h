// Source exposure: binary-analysis; no external implementation source reused.
// Static1759130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759130*);
    virtual void release(Static1759130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759130*);
struct Static1759130 {
    void* value;
    Static1759130();
    ~Static1759130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
