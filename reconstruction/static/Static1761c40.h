// Source exposure: binary-analysis; no external implementation source reused.
// Static1761c40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761c40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761c40*);
    virtual void release(Static1761c40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761c40*);
struct Static1761c40 {
    void* value;
    Static1761c40();
    ~Static1761c40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
