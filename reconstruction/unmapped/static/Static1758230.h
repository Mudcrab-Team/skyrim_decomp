// Source exposure: binary-analysis; no external implementation source reused.
// Static1758230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758230*);
    virtual void release(Static1758230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758230*);
struct Static1758230 {
    void* value;
    Static1758230();
    ~Static1758230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
