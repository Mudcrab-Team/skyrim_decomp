// Source exposure: binary-analysis; no external implementation source reused.
// Static1756890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756890*);
    virtual void release(Static1756890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756890*);
struct Static1756890 {
    void* value;
    Static1756890();
    ~Static1756890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
