// Source exposure: binary-analysis; no external implementation source reused.
// Static1756250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756250*);
    virtual void release(Static1756250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756250*);
struct Static1756250 {
    void* value;
    Static1756250();
    ~Static1756250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
