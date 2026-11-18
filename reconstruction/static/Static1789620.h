// Source exposure: binary-analysis; no external implementation source reused.
// Static1789620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789620*);
    virtual void release(Static1789620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789620*);
struct Static1789620 {
    void* value;
    Static1789620();
    ~Static1789620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
