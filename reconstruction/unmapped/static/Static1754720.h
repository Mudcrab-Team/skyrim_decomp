// Source exposure: binary-analysis; no external implementation source reused.
// Static1754720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754720*);
    virtual void release(Static1754720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754720*);
struct Static1754720 {
    void* value;
    Static1754720();
    ~Static1754720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
