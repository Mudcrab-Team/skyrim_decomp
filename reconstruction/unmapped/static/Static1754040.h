// Source exposure: binary-analysis; no external implementation source reused.
// Static1754040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754040*);
    virtual void release(Static1754040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754040*);
struct Static1754040 {
    void* value;
    Static1754040();
    ~Static1754040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
