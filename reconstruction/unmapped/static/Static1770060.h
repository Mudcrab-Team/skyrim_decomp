// Source exposure: binary-analysis; no external implementation source reused.
// Static1770060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770060*);
    virtual void release(Static1770060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770060*);
struct Static1770060 {
    void* value;
    Static1770060();
    ~Static1770060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
