// Source exposure: binary-analysis; no external implementation source reused.
// Static1751840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751840*);
    virtual void release(Static1751840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751840*);
struct Static1751840 {
    void* value;
    Static1751840();
    ~Static1751840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
