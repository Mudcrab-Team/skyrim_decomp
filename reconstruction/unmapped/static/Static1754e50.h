// Source exposure: binary-analysis; no external implementation source reused.
// Static1754e50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754e50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754e50*);
    virtual void release(Static1754e50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754e50*);
struct Static1754e50 {
    void* value;
    Static1754e50();
    ~Static1754e50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
