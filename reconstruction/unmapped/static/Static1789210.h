// Source exposure: binary-analysis; no external implementation source reused.
// Static1789210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789210*);
    virtual void release(Static1789210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789210*);
struct Static1789210 {
    void* value;
    Static1789210();
    ~Static1789210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
