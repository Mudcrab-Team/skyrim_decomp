// Source exposure: binary-analysis; no external implementation source reused.
// Static1742840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742840*);
    virtual void release(Static1742840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742840*);
struct Static1742840 {
    void* value;
    Static1742840();
    ~Static1742840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
