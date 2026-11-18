// Source exposure: binary-analysis; no external implementation source reused.
// Static1788840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788840*);
    virtual void release(Static1788840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788840*);
struct Static1788840 {
    void* value;
    Static1788840();
    ~Static1788840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
