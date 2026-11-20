// Source exposure: binary-analysis; no external implementation source reused.
// Static1781400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781400*);
    virtual void release(Static1781400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781400*);
struct Static1781400 {
    void* value;
    Static1781400();
    ~Static1781400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
