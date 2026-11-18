// Source exposure: binary-analysis; no external implementation source reused.
// Static1773f80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773f80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773f80*);
    virtual void release(Static1773f80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773f80*);
struct Static1773f80 {
    void* value;
    Static1773f80();
    ~Static1773f80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
