// Source exposure: binary-analysis; no external implementation source reused.
// Static1773300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773300*);
    virtual void release(Static1773300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773300*);
struct Static1773300 {
    void* value;
    Static1773300();
    ~Static1773300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
