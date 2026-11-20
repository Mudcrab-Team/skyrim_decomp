// Source exposure: binary-analysis; no external implementation source reused.
// Static1786720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786720*);
    virtual void release(Static1786720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786720*);
struct Static1786720 {
    void* value;
    Static1786720();
    ~Static1786720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
