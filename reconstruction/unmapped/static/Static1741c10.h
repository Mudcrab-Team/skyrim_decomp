// Source exposure: binary-analysis; no external implementation source reused.
// Static1741c10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741c10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741c10*);
    virtual void release(Static1741c10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741c10*);
struct Static1741c10 {
    void* value;
    Static1741c10();
    ~Static1741c10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
