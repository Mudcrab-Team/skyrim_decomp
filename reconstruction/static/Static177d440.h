// Source exposure: binary-analysis; no external implementation source reused.
// Static177d440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d440*);
    virtual void release(Static177d440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d440*);
struct Static177d440 {
    void* value;
    Static177d440();
    ~Static177d440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
