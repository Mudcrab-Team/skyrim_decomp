// Source exposure: binary-analysis; no external implementation source reused.
// Static1772680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772680*);
    virtual void release(Static1772680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772680*);
struct Static1772680 {
    void* value;
    Static1772680();
    ~Static1772680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
