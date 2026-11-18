// Source exposure: binary-analysis; no external implementation source reused.
// Static1781770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781770*);
    virtual void release(Static1781770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781770*);
struct Static1781770 {
    void* value;
    Static1781770();
    ~Static1781770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
