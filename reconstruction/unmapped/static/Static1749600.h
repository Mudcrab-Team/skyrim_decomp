// Source exposure: binary-analysis; no external implementation source reused.
// Static1749600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749600*);
    virtual void release(Static1749600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749600*);
struct Static1749600 {
    void* value;
    Static1749600();
    ~Static1749600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
