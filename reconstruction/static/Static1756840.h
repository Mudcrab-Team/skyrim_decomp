// Source exposure: binary-analysis; no external implementation source reused.
// Static1756840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756840*);
    virtual void release(Static1756840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756840*);
struct Static1756840 {
    void* value;
    Static1756840();
    ~Static1756840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
