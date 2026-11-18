// Source exposure: binary-analysis; no external implementation source reused.
// Static1757c90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757c90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757c90*);
    virtual void release(Static1757c90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757c90*);
struct Static1757c90 {
    void* value;
    Static1757c90();
    ~Static1757c90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
