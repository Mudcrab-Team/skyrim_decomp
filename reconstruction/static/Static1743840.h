// Source exposure: binary-analysis; no external implementation source reused.
// Static1743840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743840*);
    virtual void release(Static1743840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743840*);
struct Static1743840 {
    void* value;
    Static1743840();
    ~Static1743840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
