// Source exposure: binary-analysis; no external implementation source reused.
// Static1781040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781040*);
    virtual void release(Static1781040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781040*);
struct Static1781040 {
    void* value;
    Static1781040();
    ~Static1781040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
