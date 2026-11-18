// Source exposure: binary-analysis; no external implementation source reused.
// Static1765840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765840*);
    virtual void release(Static1765840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765840*);
struct Static1765840 {
    void* value;
    Static1765840();
    ~Static1765840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
