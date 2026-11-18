// Source exposure: binary-analysis; no external implementation source reused.
// Static1757060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757060*);
    virtual void release(Static1757060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757060*);
struct Static1757060 {
    void* value;
    Static1757060();
    ~Static1757060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
