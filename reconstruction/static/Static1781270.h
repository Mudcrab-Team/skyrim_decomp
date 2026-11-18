// Source exposure: binary-analysis; no external implementation source reused.
// Static1781270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781270*);
    virtual void release(Static1781270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781270*);
struct Static1781270 {
    void* value;
    Static1781270();
    ~Static1781270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
