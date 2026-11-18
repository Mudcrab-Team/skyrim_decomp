// Source exposure: binary-analysis; no external implementation source reused.
// Static1772630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772630*);
    virtual void release(Static1772630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772630*);
struct Static1772630 {
    void* value;
    Static1772630();
    ~Static1772630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
