// Source exposure: binary-analysis; no external implementation source reused.
// Static1795060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795060*);
    virtual void release(Static1795060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795060*);
struct Static1795060 {
    void* value;
    Static1795060();
    ~Static1795060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
