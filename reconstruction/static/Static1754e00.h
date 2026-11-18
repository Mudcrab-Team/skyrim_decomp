// Source exposure: binary-analysis; no external implementation source reused.
// Static1754e00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754e00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754e00*);
    virtual void release(Static1754e00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754e00*);
struct Static1754e00 {
    void* value;
    Static1754e00();
    ~Static1754e00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
