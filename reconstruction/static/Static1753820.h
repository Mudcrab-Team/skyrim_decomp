// Source exposure: binary-analysis; no external implementation source reused.
// Static1753820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753820*);
    virtual void release(Static1753820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753820*);
struct Static1753820 {
    void* value;
    Static1753820();
    ~Static1753820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
