// Source exposure: binary-analysis; no external implementation source reused.
// Static1773e40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773e40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773e40*);
    virtual void release(Static1773e40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773e40*);
struct Static1773e40 {
    void* value;
    Static1773e40();
    ~Static1773e40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
