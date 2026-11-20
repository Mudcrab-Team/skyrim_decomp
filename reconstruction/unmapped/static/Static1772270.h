// Source exposure: binary-analysis; no external implementation source reused.
// Static1772270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772270*);
    virtual void release(Static1772270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772270*);
struct Static1772270 {
    void* value;
    Static1772270();
    ~Static1772270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
