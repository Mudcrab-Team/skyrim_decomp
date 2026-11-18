// Source exposure: binary-analysis; no external implementation source reused.
// Static1754c20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754c20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754c20*);
    virtual void release(Static1754c20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754c20*);
struct Static1754c20 {
    void* value;
    Static1754c20();
    ~Static1754c20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
