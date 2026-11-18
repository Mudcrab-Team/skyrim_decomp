// Source exposure: binary-analysis; no external implementation source reused.
// Static1796820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796820*);
    virtual void release(Static1796820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796820*);
struct Static1796820 {
    void* value;
    Static1796820();
    ~Static1796820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
