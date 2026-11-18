// Source exposure: binary-analysis; no external implementation source reused.
// Static1780550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780550*);
    virtual void release(Static1780550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780550*);
struct Static1780550 {
    void* value;
    Static1780550();
    ~Static1780550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
