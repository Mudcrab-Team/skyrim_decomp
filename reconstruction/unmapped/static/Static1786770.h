// Source exposure: binary-analysis; no external implementation source reused.
// Static1786770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786770*);
    virtual void release(Static1786770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786770*);
struct Static1786770 {
    void* value;
    Static1786770();
    ~Static1786770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
