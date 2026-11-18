// Source exposure: binary-analysis; no external implementation source reused.
// Static1783840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783840*);
    virtual void release(Static1783840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783840*);
struct Static1783840 {
    void* value;
    Static1783840();
    ~Static1783840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
