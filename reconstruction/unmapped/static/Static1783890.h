// Source exposure: binary-analysis; no external implementation source reused.
// Static1783890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783890*);
    virtual void release(Static1783890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783890*);
struct Static1783890 {
    void* value;
    Static1783890();
    ~Static1783890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
