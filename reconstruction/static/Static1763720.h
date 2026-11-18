// Source exposure: binary-analysis; no external implementation source reused.
// Static1763720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763720*);
    virtual void release(Static1763720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763720*);
struct Static1763720 {
    void* value;
    Static1763720();
    ~Static1763720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
