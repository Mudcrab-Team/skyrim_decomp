// Source exposure: binary-analysis; no external implementation source reused.
// Static1757100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757100*);
    virtual void release(Static1757100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757100*);
struct Static1757100 {
    void* value;
    Static1757100();
    ~Static1757100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
