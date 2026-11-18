// Source exposure: binary-analysis; no external implementation source reused.
// Static1769210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769210*);
    virtual void release(Static1769210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769210*);
struct Static1769210 {
    void* value;
    Static1769210();
    ~Static1769210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
