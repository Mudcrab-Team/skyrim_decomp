// Source exposure: binary-analysis; no external implementation source reused.
// Static1785500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785500*);
    virtual void release(Static1785500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785500*);
struct Static1785500 {
    void* value;
    Static1785500();
    ~Static1785500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
