// Source exposure: binary-analysis; no external implementation source reused.
// Static1799470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799470*);
    virtual void release(Static1799470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799470*);
struct Static1799470 {
    void* value;
    Static1799470();
    ~Static1799470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
