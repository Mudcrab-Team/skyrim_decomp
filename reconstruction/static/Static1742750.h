// Source exposure: binary-analysis; no external implementation source reused.
// Static1742750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742750*);
    virtual void release(Static1742750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742750*);
struct Static1742750 {
    void* value;
    Static1742750();
    ~Static1742750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
