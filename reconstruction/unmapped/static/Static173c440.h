// Source exposure: binary-analysis; no external implementation source reused.
// Static173c440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c440*);
    virtual void release(Static173c440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c440*);
struct Static173c440 {
    void* value;
    Static173c440();
    ~Static173c440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
