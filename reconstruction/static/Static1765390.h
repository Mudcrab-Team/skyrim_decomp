// Source exposure: binary-analysis; no external implementation source reused.
// Static1765390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765390*);
    virtual void release(Static1765390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765390*);
struct Static1765390 {
    void* value;
    Static1765390();
    ~Static1765390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
