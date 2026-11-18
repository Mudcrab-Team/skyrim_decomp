// Source exposure: binary-analysis; no external implementation source reused.
// Static1781590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781590*);
    virtual void release(Static1781590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781590*);
struct Static1781590 {
    void* value;
    Static1781590();
    ~Static1781590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
