// Source exposure: binary-analysis; no external implementation source reused.
// Static1772770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772770*);
    virtual void release(Static1772770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772770*);
struct Static1772770 {
    void* value;
    Static1772770();
    ~Static1772770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
