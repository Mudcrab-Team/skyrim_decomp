// Source exposure: binary-analysis; no external implementation source reused.
// Static1755210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755210*);
    virtual void release(Static1755210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755210*);
struct Static1755210 {
    void* value;
    Static1755210();
    ~Static1755210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
