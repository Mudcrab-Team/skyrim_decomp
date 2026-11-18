// Source exposure: binary-analysis; no external implementation source reused.
// Static1762870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762870*);
    virtual void release(Static1762870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762870*);
struct Static1762870 {
    void* value;
    Static1762870();
    ~Static1762870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
