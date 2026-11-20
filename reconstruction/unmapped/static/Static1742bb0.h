// Source exposure: binary-analysis; no external implementation source reused.
// Static1742bb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742bb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742bb0*);
    virtual void release(Static1742bb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742bb0*);
struct Static1742bb0 {
    void* value;
    Static1742bb0();
    ~Static1742bb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
