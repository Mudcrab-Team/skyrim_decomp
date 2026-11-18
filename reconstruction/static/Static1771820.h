// Source exposure: binary-analysis; no external implementation source reused.
// Static1771820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771820*);
    virtual void release(Static1771820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771820*);
struct Static1771820 {
    void* value;
    Static1771820();
    ~Static1771820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
